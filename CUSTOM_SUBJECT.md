# libftpp — Further Exploration into Advanced C++

> **Note de réorganisation.** Ce fichier est une **réécriture du sujet officiel** (`libftpp.md`), **traduite en français**, dans laquelle les choses à faire de la partie obligatoire sont présentées **du plus simple au plus difficile**, pour servir de fil de travail progressif. Aucun contenu d'origine n'est perdu : règles, noms de fichiers, méthodes et indices sont conservés. Seuls l'ordre, la présentation et la langue changent.
>
> Chaque exercice est rangé dans un niveau de difficulté estimée :
> `★` = très simple → `★★★★★` = très avancé. Une indication rappelle la section d'origine du sujet (`§III.x`) et le header fédérateur (`*_*.hpp`) dans lequel la classe doit être déclarée.
>
> Les noms d'identifiants techniques (noms de classes, fichiers, signatures de méthodes) sont laissés en anglais, comme dans le sujet original.

---

## Table des matières

| Section | Contenu |
| --- | --- |
| I | Objectifs |
| II | Règles générales |
| III | Partie obligatoire (réorganisée par difficulté) |
| IV | Bonus |
| V | Rendu et évaluation par les pairs |

---

## I. Objectifs

Dans ce sujet de pointe, vous allez vous lancer dans un voyage extraordinaire au cœur du C++ afin de construire une boîte à outils qui vous accompagnera pour le reste de vos projets C++ !

Fini le temps où l'on s'appuyait uniquement sur des bibliothèques et des frameworks préfabriqués. Il est temps de prendre le contrôle, de construire des outils adaptés à vos défis uniques, et de défendre les plus hauts standards de qualité de code.

En explorant des design patterns comme Singleton et Observer, vous commencerez à voir comment l'architecture d'un logiciel efficace se déploie devant vous. Vous plongerez dans les structures de données thread-safe, repoussant vos compétences en multi-threading vers de nouveaux sommets. Imaginez écrire du code réseau si robuste qu'il pourrait gérer le streaming de tout Internet. Les algorithmes mathématiques complexes vous ont-ils déjà semblé intimidants ? N'ayez crainte ! Vous créerez vos propres classes de vecteurs personnalisables et vos générateurs de nombres aléatoires, finement réglés à vos besoins spécifiques — prouvant que vous êtes bien plus que capable.

Cette boîte à outils ne sera pas qu'un simple ensemble de classes et de méthodes ; elle sera un témoignage de vos compétences, de votre créativité et de votre maîtrise de l'un des langages de programmation les plus puissants à ce jour.

Alors préparez-vous pour une aventure incroyable, car à la fin, vous n'aurez pas seulement une boîte à outils ! Vous aurez un arsenal de compétences qui vous permettra de relever n'importe quel projet logiciel à l'avenir.

---

## II. Règles générales

### Compilation

- Compilez votre code avec **c++** et les flags **-Wall -Wextra -Werror**.
- Votre code doit compiler avec au moins le flag **-std=c++11**.

> Oui, vous devez utiliser le C++11 ou une version ultérieure.

### Conventions de formatage et de nommage

- Nommez vos fichiers, classes, fonctions, fonctions membres et attributs comme indiqué dans les consignes.
- Écrivez les noms de classes en **PascalCase**. Écrivez les noms de méthodes en **camelCase**.
- Les fichiers contenant le code d'une classe doivent toujours être nommés en **snake_case** d'après le nom de la classe. Par exemple : `class_name.hpp` / `class_name.h`, `class_name.cpp` ou `class_name.tpp`. Ainsi, si vous avez un fichier d'en-tête contenant la définition d'une classe « BrickWall » représentant un mur de briques, le fichier s'appellera `brick_wall.hpp`.
- Sauf indication contraire, chaque message de sortie doit se terminer par un caractère de nouvelle ligne et être affiché sur la sortie standard.
- **Adieu Norminette !** Aucun style de code n'est imposé dans les modules C++. Vous pouvez suivre le style que vous préférez. Cependant, rappelez-vous que si votre code est difficile à comprendre pour vos évaluateurs, ils ne pourront pas le noter. Faites donc de votre mieux pour écrire un code propre et lisible.

### Autorisé / Interdit

Vous ne codez plus en C. Il est temps de passer au C++ ! Par conséquent :

- Vous êtes autorisés à utiliser presque tout ce qui vient de la bibliothèque standard, du C++11 (au minimum) à la version la plus récente du C++. Ainsi, plutôt que de vous en tenir à ce que vous connaissez déjà, il serait judicieux d'utiliser autant que possible les versions C++ des fonctions C dont vous avez l'habitude.
- En revanche, vous ne pouvez utiliser aucune bibliothèque externe au-delà de la bibliothèque standard. Cela signifie que des bibliothèques comme **Boost** sont interdites. Les fonctions suivantes sont également interdites : **`printf()`**, **`alloc()`** et **`free()`**. Utiliser l'une d'elles entraînera automatiquement un 0 à votre note, sans exception.

### Quelques exigences de conception

- Les fuites mémoire existent aussi en C++. Lorsque vous allouez de la mémoire avec le mot-clé **`new`**, vous devez vous assurer d'éviter les **fuites mémoire**.
- Toute implémentation de fonction placée dans un fichier d'en-tête (à l'exception des templates de fonctions) entraînera une note de 0 pour cet exercice.
- Chacun de vos headers doit pouvoir être utilisé indépendamment des autres. Ils doivent donc inclure toutes les dépendances nécessaires. Cependant, vous devez empêcher le problème de la double inclusion en ajoutant des **include guards**. À défaut, la note sera de 0.

### À lire

- Vous pouvez ajouter des fichiers supplémentaires si besoin (par exemple pour organiser votre code). Ces exercices n'étant pas vérifiés automatiquement par un programme, vous êtes libres de le faire tant que vous rendez les fichiers obligatoires.

> Vous allez devoir implémenter beaucoup de classes. Cela peut sembler fastidieux à moins de pouvoir scripter votre éditeur de texte préféré. Vous disposez d'une certaine liberté dans la réalisation des exercices. Cependant, suivez les règles obligatoires et ne soyez pas paresseux — vous rateriez beaucoup d'informations précieuses ! N'hésitez pas à vous renseigner sur les concepts théoriques.

---

## III. Partie obligatoire — réorganisée du plus simple au plus difficile

### Vue d'ensemble (le parcours)

| Étape | Classe / outil | Section d'origine | Header | Difficulté |
| --- | --- | --- | --- | --- |
| 0 | Squelette du projet (Makefile + `libftpp.hpp`) | §III.1 | — | prérequis |
| 1 | Observer | §III.3 Design Patterns | `design_patterns.hpp` | ★☆☆☆☆ |
| 2 | Singleton | §III.3 Design Patterns | `design_patterns.hpp` | ★☆☆☆☆ |
| 3 | Message | §III.6 Network | `network.hpp` | ★☆☆☆☆ |
| 4 | IVector2 | §III.7 Mathematics | `mathematics.hpp` | ★☆☆☆☆ |
| 5 | IVector3 | §III.7 Mathematics | `mathematics.hpp` | ★☆☆☆☆ |
| 6 | Random2DCoordinateGenerator | §III.7 Mathematics | `mathematics.hpp` | ★☆☆☆☆ |
| 7 | ThreadSafeQueue | §III.5 Thread | `threading.hpp` | ★★☆☆☆ |
| 8 | DataBuffer | §III.2 Data Structures | `data_structures.hpp` | ★★☆☆☆ |
| 9 | Memento | §III.3 Design Patterns | `design_patterns.hpp` | ★★☆☆☆ |
| 10 | StateMachine | §III.3 Design Patterns | `design_patterns.hpp` | ★★☆☆☆ |
| 11 | ThreadSafeIOStream | §III.4 IOStream | *(fichiers directs)* | ★★★☆☆ |
| 12 | Thread | §III.5 Thread | `threading.hpp` | ★★★☆☆ |
| 13 | Pool & Pool::Object | §III.2 Data Structures | `data_structures.hpp` | ★★★★☆ |
| 14 | PersistentWorker | §III.5 Thread | `threading.hpp` | ★★★★☆ |
| 15 | WorkerPool | §III.5 Thread | `threading.hpp` | ★★★★☆ |
| 16 | Client | §III.6 Network | `network.hpp` | ★★★★☆ |
| 17 | Server | §III.6 Network | `network.hpp` | ★★★★★ |
| 18 | PerlinNoise2D | §III.7 Mathematics | `mathematics.hpp` | ★★★★★ |

**Dépendances douces** (à garder en tête, mais rien n'impose l'ordre d'origine) :

- **Message** (étape 3) est le socle de **Client** (16) et **Server** (17) : fais-le avant.
- **ThreadSafeQueue** (7) est naturellement réutilisée par **WorkerPool** (15) et **PersistentWorker** (14).
- **Thread** (12) et **ThreadSafeIOStream** (11) s'intègrent : le nom du thread sert de préfixe d'impression.
- **Memento** (9) peut s'appuyer sur un conteneur polymorphique type **DataBuffer** (8) pour sa `Snapshot`.
- Les vecteurs **IVector2/3** (4-5) font partie du §III.7 Mathematics, que le sujet officiel présente comme une section que l'on peut **sauter pour valider** (voir la note en fin de partie). Ils restent ici très tôt car ils comptent parmi les exercices les plus simples — autant engranger des points faciles.

---

### Étape 0 — Squelette du projet (fondations, à faire en premier)

*Difficulté : prérequis — aucun concept C++ avancé, mais tout le reste en dépend.*

Votre but final est de construire une toolbox C++ complète qui vous servira dans vos futurs projets. Pour garantir qu'elle soit portable et facile à intégrer, structurez votre projet ainsi :

- **Makefile** : produit une **bibliothèque statique** nommée **`libftpp.a`**, qui regroupe toutes les fonctionnalités implémentées au fil du projet. Le Makefile doit compiler `libftpp.a` avec les flags **-Wall -Wextra -Werror**.
- **Header fédérateur** : fournissez un fichier d'en-tête unifié nommé **`libftpp.hpp`**, à la **racine** du dépôt, qui inclut tous les headers nécessaires de votre toolbox. Ainsi, d'autres développeurs (ou votre futur vous-même) pourront intégrer la bibliothèque en incluant ce seul fichier.
- **Organisation** : en dehors de ces éléments essentiels, vous êtes libres d'organiser votre code comme bon vous semble. La créativité et une bonne structure sont encouragées mais pas strictement imposées. Sources et headers se rangent comme vous préférez.

> Chaque section ci-dessous réclame en plus un petit header fédérateur (`data_structures.hpp`, `design_patterns.hpp`, `threading.hpp`, `network.hpp`, `mathematics.hpp`) qui **inclut tous les headers de la section**. Créez-le au fur et à mesure, dès que vous ajoutez la première classe de la section. Attention aux **include guards** dans chaque header.

---

**Niveau 1 — Très simple (`★☆☆☆☆`)**

*Classes autonomes, un seul concept, aucun besoin de threading ni de réseau.*
*Point commun : ce sont des briques réutilisables par la suite.*

### Étape 1 — Observer

*Section d'origine : §III.3 Design Patterns — à inclure dans `design_patterns.hpp`*

- **Fichier à rendre** : `observer.hpp`
- **Description** : une classe `Observer` templatée par `TEvent`, qui permet de s'abonner à des événements et d'être notifié lorsque ces événements précis sont déclenchés.
- **Méthodes publiques** :
  - `void subscribe(const TEvent& event, const std::function<void()>& lambda)` — abonne une lambda à un événement précis.
  - `void notify(const TEvent& event)` — exécute toutes les lambdas abonnées à cet événement.
- **Indice** : utilisez le pattern Observer pour mettre à jour les objets enregistrés quand un sujet change.

---

### Étape 2 — Singleton

*Section d'origine : §III.3 Design Patterns — à inclure dans `design_patterns.hpp`*

- **Fichier à rendre** : `singleton.hpp`
- **Description** : garantit qu'une classe templatée `TType` n'a qu'une seule instance, et fournit un moyen d'y accéder.
- **Méthodes publiques** :
  - `TType* instance()` — renvoie l'instance gérée de la classe `TType`.
  - `template<typename ... TArgs> void instantiate(TArgs&& p_args)` — initialise l'instance gérée. Si l'instance est **déjà définie**, cette méthode doit **lever une exception**.
- **Indice** : cette classe doit être déclarée **`friend`** dans la classe qui en hérite.

---

### Étape 3 — Message

*Section d'origine : §III.6 Network — à inclure dans `network.hpp`*
*À faire tôt : `Client` (16) et `Server` (17) en dépendent.*

- **Fichiers à rendre** : `message.hpp`, `message.cpp`
- **Description** : gère les messages échangés entre le client et le serveur.
- **Méthodes** :
  - `Message(int type)` — constructeur prenant un entier en entrée pour décrire le type de message stocké dans l'objet.
  - Opérateurs templatés surchargés pour **`<<`**, **`>>`** (sérialisation / désérialisation).
  - `int type()` — renvoie le type du message.
- **Indice** : les classes utilisant `Message` doivent pouvoir détecter le type de message reçu, grâce à un attribut `Type` interne à `Message`, afin de décider comment le traiter.

---

### Étape 4 — IVector2

*Section d'origine : §III.7 Mathematics (section optionnelle, voir la note) — à inclure dans `mathematics.hpp`*

- **Fichiers à rendre** : `ivector2.hpp`, `ivector2.cpp`
- **Description** : un vecteur 2D au type templaté. `IVector2` doit être une **struct**, contenant les attributs :
  - `TType x` — première coordonnée du vecteur.
  - `TType y` — seconde coordonnée du vecteur.
- **Opérateurs** : surcharges avec un autre `IVector2` pour **`+`**, **`-`**, **`*`**, **`/`**, **`==`**, **`!=`**.
- **Méthodes additionnelles** :
  - `float length()` — renvoie la norme/longueur du vecteur.
  - `IVector2<float> normalize()` — renvoie la version normalisée du vecteur 2D.
  - `float dot()` — renvoie le produit scalaire du vecteur 2D.
  - `IVector2 cross()` — renvoie le produit vectoriel du vecteur 2D.
- **Indice** : utilisez la surcharge d'opérateurs C++ pour un code propre et intuitif.

---

### Étape 5 — IVector3

*Section d'origine : §III.7 Mathematics (section optionnelle) — à inclure dans `mathematics.hpp`*

- **Fichiers à rendre** : `ivector3.hpp`, `ivector3.cpp`
- **Description** : un vecteur 3D au type templaté `TType`. `IVector3` doit être une **struct**, contenant les attributs :
  - `TType x` — première coordonnée.
  - `TType y` — seconde coordonnée.
  - `TType z` — troisième coordonnée.
- **Opérateurs** : surcharges avec un autre `IVector3` pour **`+`**, **`-`**, **`*`**, **`/`**, **`==`**, **`!=`**.
- **Méthodes additionnelles** :
  - `float length()` — renvoie la norme/longueur du vecteur.
  - `IVector3<float> normalize()` — renvoie la version normalisée du vecteur 3D.
  - `float dot()` — renvoie le produit scalaire du vecteur 3D.
  - `IVector3 cross()` — renvoie le produit vectoriel du vecteur 3D.
- **Indice** : étendez les fonctionnalités à l'aide de la surcharge d'opérateurs C++.

> **Note sur les générateurs pseudo-aléatoires** (concerne l'étape 6 et l'étape 18) : il s'agit de générateurs **pseudo-aléatoires** (renseignez-vous sur ce que c'est ;)). La combinaison **Seed + Coordonnées** doit donc toujours renvoyer **le même résultat** à chaque appel. Évidemment, si vous changez la seed ou les coordonnées, le résultat doit changer.

---

### Étape 6 — Random2DCoordinateGenerator

*Section d'origine : §III.7 Mathematics (section optionnelle) — à inclure dans `mathematics.hpp`*

- **Fichiers à rendre** : `random_2D_coordinate_generator.hpp`, `random_2D_coordinate_generator.cpp`
- **Description** : génère des nombres pseudo-aléatoires à partir de coordonnées 2D.
- **Méthodes** :
  - `long long seed()` — renvoie la seed du générateur.
  - `long long operator()(const long long& x, const long long& y)` — génère un nombre pseudo-aléatoire à partir des deux valeurs passées en paramètres.
- **Indices** : utilisez les coordonnées 2D comme partie de la génération. Surchargez l'opérateur d'appel de fonction **`()`**.

---

**Niveau 2 — Simple (`★★☆☆☆`)**

*Premiers états internes, conteneurs, ou patterns qui relient deux entités.*

### Étape 7 — ThreadSafeQueue

*Section d'origine : §III.5 Thread — à inclure dans `threading.hpp`*

- **Fichier à rendre** : `thread_safe_queue.hpp`
- **Description** : une version thread-safe (templatée par `TType`) d'une file (`queue`).
- **Méthodes publiques** :
  - `void push_back(const TType& newElement)` — ajoute un élément en fin de file.
  - `void push_front(const TType& newElement)` — ajoute un élément en tête de file.
  - `TType pop_back()` — extrait le dernier élément de la file.
  - `TType pop_front()` — extrait le premier élément de la file.
- **Indices** : utilisez des mutex ou d'autres mécanismes pour la thread-safety. Si un utilisateur tente de pop un élément d'une file **vide**, il faut **lever une exception**.

---

### Étape 8 — DataBuffer

*Section d'origine : §III.2 Data Structures — à inclure dans `data_structures.hpp`*

- **Fichiers à rendre** : `data_buffer.hpp`, `data_buffer.cpp`
- **Description** : un conteneur **polymorphique** pour stocker des objets au format **octets**.
- **Méthodes** : surcharges d'opérateurs templatées pour **`<<`**, **`>>`**.
- **Indice** : utilisez les opérateurs de flux C++ pour la sérialisation et la désérialisation.

---

### Étape 9 — Memento

*Section d'origine : §III.3 Design Patterns — à inclure dans `design_patterns.hpp`*

- **Fichiers à rendre** : `memento.hpp`, `memento.cpp`
- **Description** : stocke l'état courant d'un objet. Doit être hérité par la classe « saveable ».
- **Méthodes** :
  - `Snapshot save()` — sauvegarde l'état courant de l'objet.
  - `void load(const Memento::Snapshot& state)` — charge l'état fourni.
- **Méthodes privées à implémenter dans la classe héritante** :
  - `void _saveToSnapshot(Memento::Snapshot& snapshot) const` — sauvegarde les données voulues dans la snapshot.
  - `void _loadFromSnapshot(Memento::Snapshot& snapshot)` — charge les données depuis la snapshot.
- **Indices** : l'implémentation doit permettre une restauration facile. Réfléchissez à un moyen de sauvegarder/charger simplement des données dans quelque chose comme un **conteneur polymorphique**… Votre `Memento` peut aussi avoir besoin d'accéder à ces méthodes privées, `_saveToSnapshot` et `_loadFromSnapshot`. Je me demande s'il existe une façon **friendly** de faire ça…

---

### Étape 10 — StateMachine

*Section d'origine : §III.3 Design Patterns — à inclure dans `design_patterns.hpp`*

- **Fichier à rendre** : `state_machine.hpp`
- **Description** : une classe `StateMachine` templatée par `TState`, gérant les transitions entre états.
- **Méthodes publiques** :
  - `void addState(const TState& state)` — ajoute un état possible à l'objet.
  - `void addTransition(const TState& startState, const TState& finalState, const std::function<void()>& lambda)` — précise quoi exécuter lors d'une transition donnée.
  - `void addAction(const TState& state, const std::function<void()>& lambda)` — précise quoi exécuter quand la StateMachine est dans un état donné.
  - `void transitionTo(const TState& state)` — exécute la transition vers un état donné.
  - `void update()` — exécute l'action enregistrée pour l'état courant.
- **Indices** : gérez les transitions d'état proprement et efficacement. Si une transition ou une mise à jour n'est pas paramétrée par l'utilisateur, la StateMachine doit **lever une exception**.

---

**Niveau 3 — Moyen (`★★★☆☆`)**

*Premiers contacts avec la concurrence et les flux.*

### Étape 11 — ThreadSafeIOStream

*Section d'origine : §III.4 IOStream — fichiers directs (pas de header de section)*

- **Fichiers à rendre** : `thread_safe_iostream.cpp`, `thread_safe_iostream.hpp`
- **Description** : une version thread-safe de `iostream`.
- **Méthodes publiques** :
  - Surcharges d'opérateurs pour **`<<`**, **`>>`**.
  - `void setPrefix(const std::string& prefix)` — définit le préfixe affiché avant chaque ligne quand on utilise vos surcharges d'`iostream`.
  - `template<typename T> void prompt(const std::string& question, T& dest)` — pose une question et lit la réponse dans `dest`.
- **Indices** : assurez-vous que ce soit **thread-safe** et **thread-local**, avec un préfixe ajouté à chaque ligne. Fournissez aussi un équivalent à `std::cout` pour ne pas avoir à créer un `iostream` custom : nous attendons quelque chose comme `thread_local ThreadSafeIOStream threadSafeCout;` dans votre fichier header.

---

### Étape 12 — Thread

*Section d'origine : §III.5 Thread — à inclure dans `threading.hpp`*

- **Fichiers à rendre** : `thread.hpp`, `thread.cpp`
- **Description** : un wrapper pour `std::thread`, avec un nom.
- **Méthodes publiques** :
  - `Thread(const std::string& name, std::function<void()> functToExecute)` — constructeur qui prépare les données du thread, en attendant un appel à **`start()`** pour lancer la fonction.
  - `void start()` — lance le thread, exécutant la fonction passée en paramètre au constructeur.
  - `void stop()` — arrête le thread, en le joignant correctement.
- **Indices** : le nom du thread doit être utilisé par **`ThreadSafeIOStream`** et lui fournir un préfixe indiquant quel thread imprime.

---

**Niveau 4 — Avancé (`★★★★☆`)**

*Gestion de ressources/mémoire à durée de vie délicate, machines à jobs, réseau mono-client.*

### Étape 13 — Pool & Pool::Object

*Section d'origine : §III.2 Data Structures — à inclure dans `data_structures.hpp`*

- **Fichier à rendre** : `pool.hpp`
- **Description** : gère une collection d'objets `TType` templatés réutilisables, fournis à l'utilisateur via une classe `Pool::Object`. Cette classe gère le pointeur acquis, et le **rend au pool** quand nécessaire, en appelant le **destructeur** de l'objet `TType` **sans désallouer la mémoire**.
- **Méthodes de `Pool`** :
  - `void resize(const size_t& numberOfObjectStored)` — alloue un certain nombre d'objets `TType` dans le Pool.
  - `template<typename ... TArgs> Pool::Object<TType> acquire(TArgs&& p_args)` — crée un `Pool::Object` contenant un objet pré-alloué, en utilisant le constructeur correspondant aux paramètres `TArgs`.
- **Méthode de `Pool::Object`** :
  - `TType* operator ->()` — renvoie le pointeur stocké dans le `Pool::Object`.
- **Indices** : chaque demande et chaque libération d'objet pré-alloué doit être gérée par `Pool::Object`, **pas par l'utilisateur** ! Si la notion de template `TArgs` vous est inconnue, regardez les **variadic templates** : c'est cool et élégant.

---

### Étape 14 — PersistentWorker

*Section d'origine : §III.5 Thread — à inclure dans `threading.hpp`*

- **Fichiers à rendre** : `persistent_worker.hpp`, `persistent_worker.cpp`
- **Description** : un thread qui exécute en continu un ensemble de tâches définies par l'utilisateur.
- **Méthodes** :
  - `void addTask(const std::string& name, const std::function<void()>& jobToExecute)` — insère une tâche dans le pool de tâches du worker, en lui donnant un nom.
  - `void removeTask(const std::string& name)` — retire une tâche du pool de tâches du worker.
- **Indices** : doit maintenir une liste de tâches à exécuter **en boucle**.

---

### Étape 15 — WorkerPool

*Section d'origine : §III.5 Thread — à inclure dans `threading.hpp`*

- **Fichiers à rendre** : `worker_pool.hpp`, `worker_pool.cpp`
- **Description** : gère des threads de travail pour exécuter des jobs. Il contient une sous-classe **`IJobs`**, qui décrit l'interface d'un job à exécuter par le pool.
- **Méthodes** :
  - `void addJob(const std::function<void()>& jobToExecute)` — insère un nouveau job à exécuter par le pool.
- **Indices** : les threads doivent tourner **perpétuellement**.

---

### Étape 16 — Client

*Section d'origine : §III.6 Network — à inclure dans `network.hpp`*
*À faire après Message (3) et avant Server (17).*

- **Fichiers à rendre** : `client.hpp`, `client.cpp`
- **Description** : le réseau côté client.
- **Méthodes** :
  - `void connect(const std::string& address, const size_t& port)` — se connecte au serveur précisé par adresse et port.
  - `void disconnect()` — se déconnecte du serveur.
  - `void defineAction(const Message::Type& messageType, const std::function<void(const Message& msg)>& action)` — abonne une action à un type de message précis.
  - `void send(const Message& message)` — envoie un message au serveur connecté.
  - `void update()` — traite tous les messages reçus depuis le dernier appel à `update`, et exécute l'action abonnée par l'utilisateur pour chaque message.
- **Indices** : doit fonctionner sans accroc avec les classes `Server` et `Message`.

---

**Niveau 5 — Très avancé (`★★★★★`)**

*Intégration multi-clients, ou algorithme mathématique lourd.*

### Étape 17 — Server

*Section d'origine : §III.6 Network — à inclure dans `network.hpp`*

- **Fichiers à rendre** : `server.hpp`, `server.cpp`
- **Description** : le réseau côté serveur.
- **Méthodes** :
  - `void start(const size_t& p_port)` — démarre le serveur sur le port spécifié.
  - `void defineAction(const Message::Type& messageType, const std::function<void(long long& clientID, const Message& msg)>& action)` — abonne une action à un type de message précis.
  - `void sendTo(const Message& message, long long clientID)` — envoie un message à un ID de client précis.
  - `void sendToArray(const Message& message, std::vector<long long> clientIDs)` — envoie un message à un ensemble précis d'IDs de clients.
  - `void sendToAll(const Message& message)` — envoie un message à tous les clients actuellement connectés au serveur.
  - `void update()` — traite tous les messages reçus depuis le dernier appel à `update`, et exécute l'action abonnée par l'utilisateur pour chaque message.
- **Indices** : doit gérer plusieurs clients et le routage des messages.

---

### Étape 18 — PerlinNoise2D

*Section d'origine : §III.7 Mathematics (section optionnelle) — à inclure dans `mathematics.hpp`*

- **Fichiers à rendre** : `perlin_noise_2D.hpp`, `perlin_noise_2D.cpp`
- **Description** : génère du bruit de Perlin 2D.
- **Méthodes** :
  - `float sample(x, y)` — renvoie une valeur de bruit de Perlin pour les coordonnées fournies.
- **Indices** : surchargez l'opérateur d'appel de fonction **`()`** pour générer le bruit à partir de coordonnées.

---

> **Note du sujet (section Mathematics).** « You can pass this subject without doing the next section. » Autrement dit, la section Mathematics (§III.7) n'est pas indispensable pour valider le sujet. C'est pour cela qu'elle reste représentée ici par des exercices de difficulté très variée (IVector2/3 sont faciles, PerlinNoise2D est dur) : engrangez les points faciles quand vous voulez, gardez Perlin pour la fin.

---

## IV. Bonus

Nous vous encourageons vivement à créer toute classe que vous jugez pertinente. Voici quelques idées de classes bonus possibles !

- **Timer** — permet de définir une durée et de vérifier si elle est écoulée, en utilisant l'heure système.
- **Chronometer** — permet de mesurer des durées, en utilisant l'heure système.
- **Application and Widget** — permet de créer des applications personnalisées aux comportements intéressants.
- **ObservableValue** — notifie les abonnés lorsque la valeur est modifiée.

Cette liste n'est pas exhaustive, alors n'hésitez pas à ajouter tout ce qui vous semble pertinent. Cependant, vous devez justifier vos choix et fournir des tests pour démontrer le fonctionnement des classes que vous créez.

**Chaque classe créée vous rapportera 5 points de bonus.**

> La partie bonus ne sera évaluée que si la partie obligatoire est **PARFAITE**. Parfaite signifie que la partie obligatoire a été réalisée dans son intégralité et fonctionne sans le moindre défaut. Si vous ne remplissez pas **TOUTES** les exigences obligatoires, votre partie bonus ne sera pas évaluée.

---

## V. Rendu et évaluation par les pairs

Rendez votre travail dans votre dépôt **Git** comme d'habitude. Seul le travail présent dans votre dépôt sera évalué lors de la soutenance. Vérifiez bien les noms de vos fichiers pour vous assurer qu'ils sont corrects.

Vous êtes libres d'organiser votre code et vos includes comme bon vous semble, mais vous devez fournir un Makefile qui construit une bibliothèque nommée **`libftpp.a`**, ainsi qu'un fichier d'inclusion nommé **`libftpp.hpp`** à la racine de votre dépôt.
