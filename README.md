# Minitalk

**Minitalk** est un projet de l'école 42 qui consiste à implémenter un système de communication entre un client et un serveur en utilisant exclusivement des signaux UNIX. Ce projet permet de se familiariser avec la gestion des signaux et les communications inter-processus.

---

## 📝 Description du Projet

Le projet se compose de deux programmes :

1. **Le serveur** :
   - Doit être lancé en premier.
   - Affiche son PID (Process ID) au lancement.
   - Reçoit une chaîne de caractères envoyée par le client et l'affiche.

2. **Le client** :
   - Prend deux arguments en paramètre : 
     - Le PID du serveur.
     - Une chaîne de caractères à transmettre.
   - Transmet la chaîne au serveur à l'aide de signaux UNIX.

#### 🔑 Notions Clés

- Gestion des signaux UNIX (`SIGUSR1`, `SIGUSR2`).
- Communication inter-processus.
- Utilisation des fonctions comme `kill`, `signal`, `sigaction`, et `pause`.
- Respect des normes de codage imposées par l'école 42.

---

## 📋 Structure du Projet

### 1. Partie Obligatoire

- Implémentation des programmes `client` et `server`.
- Le serveur doit pouvoir :
  - Recevoir et afficher les chaînes envoyées par le client.
  - Gérer plusieurs clients successivement sans redémarrer.
- Les signaux utilisés pour la communication sont exclusivement `SIGUSR1` et `SIGUSR2`.

### 2. Partie Bonus

Les bonus incluent :
- Confirmation de réception de chaque message par le serveur en renvoyant un signal au client.
- Prise en charge des caractères Unicode.

Les bonus ne sont évalués que si la partie obligatoire est parfaitement fonctionnelle.

---

## ⚙️ Instructions d'Utilisation

1. **Cloner le dépôt** :  
   ```bash
   git clone https://github.com/0x2Anessie/42-MiniTalk.git
   ```
   ```bash
   cd 42-MiniTalk
   ```

2. **Compiler le projet:**
   ```bash
   make
   ```

3. **Ouvrir deux terminaux.**
   
4. **Lancer le serveur dans un des terminaux :
   ```bash
   ./server
   ```

5. **Lancer le client dans l'autre terminal :**
   ```bash
   ./client <PID_du_serveur> "Votre message ici"
   ```
   
### Partie Bonus

1. **Pour le premier bonus le server devrait envoyer une confirmation de reception du message du client.**

2. **Pour le deuxieme, il suffit d'envoyer un caractere unicode avec le client et voir si le serveur le prend en charge.**

---

## 🛠️ Rendu

- Le dépôt Git doit contenir :
  - Les fichiers sources nécessaires pour les programmes `client` et `server`.
  - Un `Makefile` avec les règles suivantes :
    - `make` : Compile les programmes `client` et `server`.
    - `make clean` : Supprime les fichiers objets.
    - `make fclean` : Supprime les fichiers objets et les exécutables.
    - `make re` : Recompile tout depuis le début.
- Tous les fichiers inutilisés ou non demandés ne doivent pas être inclus dans le dépôt.
- La norme de l'école 42 doit être strictement respectée.
- Le projet doit être fonctionnel et exempt de fuites mémoire.

---

## 📜 Licence

Ce projet est soumis aux règles de l'école 42.
