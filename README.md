# Arma 3 RP Server

Structure de base pour un serveur Arma 3 Roleplay avec tous les fichiers de configuration nécessaires.

## 📁 Structure du Projet

```
arma3-rp-server/
├── mpmissions/         # Missions multijoueur
├── addons/             # Mods et scripts personnalisés
├── keys/               # Clés de signature BattlEye
├── database/           # Configuration et schéma de base de données
├── logs/               # Logs du serveur
├── server.cfg          # Configuration principale du serveur
├── basic.cfg           # Configuration basique
├── start_server.sh     # Script de démarrage (Linux)
├── start_server.bat    # Script de démarrage (Windows)
└── INSTALL.md          # Guide d'installation détaillé
```

## 🚀 Démarrage Rapide

### Prérequis
- Arma 3 Dedicated Server installé
- MySQL/MariaDB pour la base de données
- Ports 2302-2306 (UDP) ouverts

### Installation

1. **Cloner ce repository dans votre dossier serveur Arma 3**
   ```bash
   git clone https://github.com/cedricboyer1103-star/arma3-rp-server.git
   ```

2. **Copier les fichiers de configuration**
   ```bash
   cp server.cfg /chemin/vers/arma3server/
   cp basic.cfg /chemin/vers/arma3server/
   ```

3. **Configurer la base de données**
   ```bash
   mysql -u root -p < database/schema.sql
   ```

4. **Modifier les mots de passe dans server.cfg**
   - `passwordAdmin` - Mot de passe administrateur
   - `serverCommandPassword` - Mot de passe commande serveur

5. **Démarrer le serveur**
   ```bash
   # Linux
   ./start_server.sh
   
   # Windows
   start_server.bat
   ```

## 📖 Documentation

### Fichiers de Configuration

#### server.cfg
Configuration principale du serveur incluant:
- Nom du serveur et mots de passe
- Paramètres de sécurité
- Configuration réseau
- Rotation des missions
- Paramètres de performance

#### basic.cfg
Configuration de base pour les performances réseau et graphiques du serveur.

#### database/schema.sql
Schéma de base de données MySQL incluant les tables pour:
- Joueurs (inventaire, argent, position)
- Véhicules
- Maisons/propriétés
- Gangs/factions
- Logs serveur

### Répertoires

#### mpmissions/
Contient les fichiers de mission multijoueur. Chaque mission doit être dans un dossier au format `NomMission.NomCarte` (ex: `Altis_Life.Altis`).

#### addons/
Contient les mods et scripts personnalisés pour le serveur RP.

#### keys/
Contient les clés BattlEye pour la vérification des signatures des mods.

#### logs/
Contient tous les logs du serveur (connexions, erreurs, BattlEye).

## ⚙️ Configuration

### Paramètres Importants

**Sécurité:**
- Changez tous les mots de passe par défaut
- Activez BattlEye (`BattlEye = 1`)
- Configurez la vérification des signatures (`verifySignatures = 2`)

**Performance:**
- Ajustez `maxPlayers` selon votre matériel
- Configurez `MinBandwidth` et `MaxBandwidth` selon votre connexion
- Optimisez les paramètres CPU dans le script de démarrage

**Base de Données:**
- Créez un utilisateur MySQL dédié
- Utilisez un mot de passe fort
- Effectuez des sauvegardes régulières

## 🎮 Fonctionnalités RP

La structure de base supporte les fonctionnalités RP suivantes:

- ✅ Système d'économie (argent liquide et banque)
- ✅ Gestion des véhicules persistants
- ✅ Système de propriétés/maisons
- ✅ Gangs et factions
- ✅ Niveaux de profession (Police, Médecin, etc.)
- ✅ Inventaires persistants
- ✅ Logs pour administration
- ✅ Système de sauvegarde automatique

## 🔧 Personnalisation

### Ajouter une Mission
1. Placez votre mission dans `mpmissions/`
2. Ajoutez-la dans `server.cfg` sous `class Missions`
3. Redémarrez le serveur

### Ajouter des Mods
1. Téléchargez le mod depuis Steam Workshop
2. Placez-le dans `addons/@NomDuMod/`
3. Ajoutez `-mod=@NomDuMod` dans le script de démarrage
4. Copiez la clé du mod dans `keys/`

### Modifier le Schéma de Base de Données
1. Éditez `database/schema.sql`
2. Appliquez les changements: `mysql -u root -p arma3_rp < database/schema.sql`
3. Adaptez vos scripts de mission en conséquence

## 📋 Mods Recommandés

- **CBA_A3** - Community Base Addons (requis pour la plupart des mods)
- **Task Force Radio** - Système de communication réaliste
- **Altis Life Framework** - Framework RP complet
- **Advanced Towing** - Système de remorquage
- **Enhanced Movement** - Amélioration des mouvements

## 🛡️ Sécurité

**Important:**
- ⚠️ Changez immédiatement tous les mots de passe par défaut
- ⚠️ N'exposez jamais les mots de passe dans les commits Git
- ⚠️ Effectuez des sauvegardes régulières de la base de données
- ⚠️ Gardez le serveur et les mods à jour
- ⚠️ Surveillez les logs pour détecter les activités suspectes

## 🐛 Dépannage

### Le serveur ne démarre pas
- Vérifiez `logs/server.log` pour les erreurs
- Assurez-vous que tous les fichiers de config sont présents
- Vérifiez les permissions des fichiers (Linux)

### Les joueurs ne peuvent pas se connecter
- Vérifiez que les ports 2302-2306 UDP sont ouverts
- Assurez-vous que le serveur est en cours d'exécution
- Vérifiez que les mods correspondent entre client et serveur

### Problèmes de base de données
- Vérifiez que MySQL est en cours d'exécution
- Testez la connexion avec les identifiants configurés
- Vérifiez les logs pour les erreurs SQL

## 📚 Ressources

- [Documentation Arma 3 Server](https://community.bistudio.com/wiki/Arma_3:_Dedicated_Server)
- [Forums Bohemia Interactive](https://forums.bohemia.net/)
- [Guide d'installation détaillé](INSTALL.md)

## 📝 Licence

Ce projet est fourni "tel quel" sans garantie. Utilisez à vos propres risques.

## 🤝 Contribution

Les contributions sont les bienvenues! N'hésitez pas à:
- Signaler des bugs
- Proposer des améliorations
- Soumettre des pull requests

## ⭐ Support

Si vous trouvez ce projet utile, n'hésitez pas à lui donner une étoile!