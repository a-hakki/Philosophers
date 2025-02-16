# Philosophers

![image.png](Philosophers%2018bbea9647ac80e8817de69e1e365403/image.png)

![image.png](Philosophers%2018bbea9647ac80e8817de69e1e365403/image%201.png)

### Commande pour voir les threads

```jsx
ps -a -T
```

```jsx
htop
```

## Pour arreter le programme proprement :

Il y a 2 cas soit lorsque l’on atteint le nombre maximum de meal mangé soit lorsque un des philosophe meurt.

Donc avec notre code, pour quitter proprement il n’est pas necessaire de faire un autre thread, il suffit de quitter check_death avec return, laisser faire les pthread_join et arreter les boucles infinies de la fonction routine lorsque un des philosophes meurt ou le nombre de plats est atteint.

# NOTIONS

## Thread, Processus, Coeur

---

### **1. Le processeur et ses cœurs**

- Ton **processeur** (CPU) est le cerveau de ton PC.
- Il est composé de **plusieurs cœurs** (CPU cores), qui sont comme des "mini-processeurs" capables d'exécuter des tâches en parallèle.
- **Exemple** : Si ton processeur a **4 cœurs**, il peut exécuter **4 tâches** en même temps.

💡 **Imagine un restaurant avec 4 cuisiniers.**

- Chaque cuisinier (cœur) peut préparer un plat en même temps.
- Plus il y a de cuisiniers, plus de plats peuvent être préparés en parallèle.

---

### **2. Processus : Un programme en cours d'exécution**

- Un **processus** est une application ou un programme qui tourne sur ton ordinateur.
- Chaque processus a **son propre espace mémoire**.
- Un PC peut exécuter **des centaines de processus** en même temps.

💡 **Exemple :**

- Ouvrir **Google Chrome** crée un **processus**.
- Ouvrir **un deuxième onglet** peut créer un **nouveau processus** (car Chrome utilise un processus par onglet).

---

### **3. Threads : Petites tâches à l'intérieur d'un processus**

- Un **thread** est une **sous-partie d’un processus**.
- **Tous les threads d'un même processus partagent la même mémoire** et peuvent travailler ensemble.
- Un processus peut avoir **un seul thread** (exécution séquentielle) ou **plusieurs threads** (exécution parallèle).

💡 **Exemple :**

- Dans un **jeu vidéo**, il y a :
    - Un thread pour **l’affichage**
    - Un thread pour **le son**
    - Un thread pour **les contrôles du joueur**

Tous ces threads appartiennent au même processus du jeu.

---

### **4. Comment les processus et threads sont répartis sur les cœurs ?**

- L’**ordinateur choisit automatiquement** quel processus ou thread est exécuté sur quel cœur.
- Si tu as **4 cœurs** et **8 processus en cours**, l’OS va **répartir les processus sur les cœurs** pour équilibrer la charge.
- Un **thread ou un processus peut changer de cœur** selon les besoins.

💡 **Exemple avec 4 cœurs :**

| Cœur | Tâches en cours |
| --- | --- |
| Cœur 1 | Processus A (Thread 1) |
| Cœur 2 | Processus A (Thread 2) |
| Cœur 3 | Processus B |
| Cœur 4 | Processus C |

Un thread peut commencer sur **Cœur 1**, puis être déplacé sur **Cœur 3** si besoin.

---

### **5. Résumé simple**

- **Un processeur** a **plusieurs cœurs** (ex : 4 cœurs = 4 tâches en parallèle).
- **Un processus** est un programme en cours d'exécution.
- **Un thread** est une sous-partie d'un processus, et plusieurs threads peuvent être exécutés en même temps sur différents cœurs.
- L’**OS gère automatiquement** la répartition des processus et threads sur les cœurs.

## Mutex, Data Races, Deadlock

---

## **1. Mutex (Mutual Exclusion)**

Un **mutex** est un **verrou** qui empêche plusieurs threads d'accéder à une ressource en même temps.

💡 **Exemple concret :**

Imagine que 5 philosophes partagent une table avec **5 fourchettes**, mais pour manger, ils ont besoin de **2 fourchettes** en même temps.

- Si deux philosophes essaient de prendre **la même fourchette**, ça pose un problème.
- Le **mutex** permet de "verrouiller" une fourchette pour qu'un seul philosophe puisse l'utiliser à la fois.

### **Comment fonctionne un mutex en C ?**

1. **Déclaration** d'un mutex :
    
    ```c
    pthread_mutex_t mutex;
    ```
    
2. **Initialisation** du mutex :
    
    ```c
    pthread_mutex_init(&mutex, NULL);
    
    ```
    
3. **Verrouillage** avant d’accéder à une ressource :
    
    ```c
    pthread_mutex_lock(&mutex);
    ```
    
4. **Déverrouillage** une fois terminé :
    
    ```c
    pthread_mutex_unlock(&mutex);
    ```
    
5. **Destruction** (quand il n’est plus nécessaire) :
    
    ```c
    pthread_mutex_destroy(&mutex);
    ```
    

🔹 **Dans le projet Philosophers**, les fourchettes sont protégées par des **mutex** pour éviter que deux philosophes prennent la même en même temps.

---

## **2. Data Race (Course de données)**

Un **data race** se produit quand **deux threads accèdent à la même variable en même temps**, et au moins un d'eux **écrit** dans cette variable.

💡 **Exemple concret :**

Imagine que **deux philosophes** lisent et écrivent en même temps sur la même assiette !

- Philosophe 1 : "J'ajoute une bouchée de pâtes 🍝"
- Philosophe 2 : "Je vide l'assiette 🍽️"
- Le résultat final est **imprévisible** !

### **Exemple de data race en C (Problème)**

```c
int shared_var = 0;

void *increment(void *arg) {
    for (int i = 0; i < 1000000; i++)
        shared_var++;  // ⚠️ Data race possible
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Valeur finale : %d\n", shared_var);  // Résultat inattendu
    return 0;
}
```

🔹 **Le problème ?** `shared_var` est modifié en même temps par deux threads **sans protection**.

🔹 **Solution ?** Utiliser un **mutex** autour de `shared_var` !

---

## **3. Deadlock (Blocage)**

Un **deadlock** se produit quand **deux threads attendent une ressource que l’autre possède**, et ils restent bloqués **indéfiniment**.

💡 **Exemple concret (Problème des philosophes) :**

- Philosophe 1 prend **Fourchette A** et attend **Fourchette B**.
- Philosophe 2 prend **Fourchette B** et attend **Fourchette A**.
- **Résultat ?** Ils attendent tous les deux indéfiniment → **Deadlock** !

### **Exemple de deadlock en C (Problème)**

```c
pthread_mutex_t fork1, fork2;

void *philosopher1(void *arg) {
    pthread_mutex_lock(&fork1);
    pthread_mutex_lock(&fork2);  // ⚠️ Deadlock possible
    printf("Philosophe 1 mange 🍽️\n");
    pthread_mutex_unlock(&fork2);
    pthread_mutex_unlock(&fork1);
    return NULL;
}

void *philosopher2(void *arg) {
    pthread_mutex_lock(&fork2);
    pthread_mutex_lock(&fork1);  // ⚠️ Deadlock possible
    printf("Philosophe 2 mange 🍽️\n");
    pthread_mutex_unlock(&fork1);
    pthread_mutex_unlock(&fork2);
    return NULL;
}
```

🔹 **Le problème ?** Si `philosopher1` verrouille `fork1` et `philosopher2` verrouille `fork2`, ils attendent **indéfiniment**.

### **Solutions pour éviter un deadlock**

✅ **Toujours prendre les fourchettes dans le même ordre** (ex: toujours prendre la fourchette gauche d'abord).

✅ **Utiliser un arbitre** (ex: un thread maître qui autorise les philosophes à manger).

✅ **Utiliser un timeout** (ex: si un philosophe attend trop longtemps, il lâche sa fourchette et réessaie).

---

## **4. Starvation (Famine)**

Un **thread est affamé (starvation)** si **il n'a jamais accès aux ressources** parce que d'autres threads les prennent tout le temps.

💡 **Exemple concret :**

- Un philosophe attend une fourchette, mais les autres philosophes mangent **sans jamais lui laisser une chance**.

### **Solution contre la famine**

✅ **Attribuer un temps d’attente limité** → S'il attend trop longtemps, il force une nouvelle tentative.

✅ **Gérer l'ordre de priorité** → Donner la priorité aux philosophes qui ont moins mangé.

---

## **5. Livelock (Verrouillage actif)**

Un **livelock** est similaire à un **deadlock**, sauf que les threads ne sont **pas bloqués**, mais ils passent leur temps à essayer d’éviter le problème **sans avancer**.

💡 **Exemple concret :**

- Deux personnes essaient de se croiser dans un couloir :
    - Elles vont à gauche en même temps → elles bloquent.
    - Elles vont à droite en même temps → toujours bloquées.
    - Elles continuent à bouger **sans avancer** → **Livelock** !

🔹 **Dans Philosophers**, un livelock peut arriver si les philosophes posent et reprennent les fourchettes **trop vite sans jamais manger**.

---

## **Conclusion**

Ces concepts sont **essentiels** pour bien comprendre le projet Philosophers et la programmation concurrente en général !

| **Concept** | **Problème** | **Solution** |
| --- | --- | --- |
| **Mutex** | Protéger une ressource partagée | `pthread_mutex_lock()` & `pthread_mutex_unlock()` |
| **Data Race** | Deux threads modifient la même variable en même temps | Protéger avec un **mutex** |
| **Deadlock** | Deux threads attendent indéfiniment une ressource | Prendre les ressources **toujours dans le même ordre** |
| **Starvation** | Un thread n’a jamais accès aux ressources | Donner la priorité aux threads qui attendent le plus longtemps |
| **Livelock** | Les threads "dansent" sans avancer | Ajouter un délai avant de réessayer |

---

💡 **Besoin d’un exemple spécifique en code ou une explication plus détaillée ?** 😃

## CodeQuoi

### **Qu’est-ce qu’un thread ?**

Un **thread** (ou fil d'exécution) est une suite d'instructions gérée par le noyau du système d'exploitation. Un programme standard utilise un seul thread, mais les systèmes modernes peuvent en exécuter plusieurs simultanément. Chaque thread a son propre contexte (identifiant, pile d'exécution, pointeur d’instruction, registre de processeur) mais partage l’espace mémoire du processus (code, heap, bibliothèques, descripteurs de fichiers).

Les threads sont plus légers que les processus, facilitant leur création et gestion. Ils ne suivent pas la hiérarchie père-fils des processus, et n'importe quel thread peut en attendre un autre.

### **Utiliser les Threads POSIX**

En C, on utilise la bibliothèque **`<pthread.h>`** pour gérer les threads, et on compile avec **`-pthread`**.

### **Créer un thread**

On crée un thread avec **`pthread_create`** :

```c
int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
```

- **`thread`** : pointeur vers un identifiant de thread.
- **`attr`** : attributs du thread (généralement `NULL`).
- **`start_routine`** : fonction que le thread exécute, avec le prototype `void *fonction(void *arg);`.
- **`arg`** : argument transmis à la fonction de thread.

La fonction renvoie 0 si elle réussit, ou un code erreur.

### **Récupérer un thread ou le détacher**

**`pthread_join`** permet de bloquer un thread principal jusqu’à ce qu'un thread spécifique se termine :

```c
int pthread_join(pthread_t thread, void **retval);
```

- **`thread`** : thread à attendre.
- **`retval`** : pointeur vers la valeur de retour de la fonction du thread (peut être `NULL`).

**`pthread_detach`** détache un thread pour qu’il soit récupéré automatiquement après son exécution, sans attendre sa fin :

```c
int pthread_detach(pthread_t thread);
```

### **Gérer la mémoire partagée entre threads**

Les threads partagent l’espace mémoire de leur processus, facilitant la communication entre eux, mais cela crée des risques d'erreurs de synchronisation.

### **Data Race (Situation de compétition)**

Quand deux threads accèdent simultanément à la même donnée sans synchronisation, cela peut mener à des erreurs. Par exemple, si deux threads lisent et modifient un compteur en même temps, ils peuvent écraser leurs résultats, créant une **"data race"**.

### **Qu’est-ce qu’un mutex ?**

Un **mutex** (exclusion mutuelle) est une primitive de synchronisation utilisée pour éviter l'accès simultané à des ressources partagées.

### **Déclarer et utiliser un mutex**

Un mutex est déclaré comme suit :

```c
pthread_mutex_t mutex;
```

Il doit être initialisé avec **`pthread_mutex_init`** :

```c
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
```

- **`mutex`** : pointeur vers le mutex.
- **`mutexattr`** : attributs (souvent `NULL`).

Ensuite, on utilise **`pthread_mutex_lock`** pour verrouiller le mutex, et **`pthread_mutex_unlock`** pour le déverrouiller :

```c
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```

Ces fonctions assurent que les threads ne peuvent pas accéder aux ressources partagées simultanément. Si un mutex est déjà verrouillé, le thread appelant attend qu’il soit déverrouillé.

### **Détruire un mutex**

Une fois un mutex inutilisé, il est détruit avec **`pthread_mutex_destroy`** :

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

### **Attention aux interblocages (Deadlocks)**

Un **deadlock** survient quand deux threads attendent des ressources détenues par l’autre, créant une situation bloquée. Cela peut arriver si un thread verrouille un mutex et attend un autre, et vice-versa.

### **Gérer les interblocages**

Il existe plusieurs stratégies pour gérer les deadlocks :

- Ignorer les deadlocks si on peut prouver qu'ils ne se produiront jamais.
- Corriger les deadlocks en tuant un thread ou en redistribuant les ressources.
- Prévenir les deadlocks en imposant un ordre d'acquisition des ressources.

### **Tester les threads**

Les erreurs de synchronisation ne sont pas toujours visibles immédiatement, il est donc important de répéter les tests. Des outils comme **ThreadSanitizer** et **Valgrind** peuvent aider à détecter des erreurs comme les **data races** et les deadlocks.

---

Ce résumé conserve les explications sur les prototypes des fonctions tout en simplifiant les exemples pour mieux comprendre le fonctionnement des threads en C et la gestion des ressources partagées.