# 💳〰️💻 QtNFCReaderGUI

<p>&nbsp;</p>

## ❔ About
This project is a simple GUI interface for reading & storing values to/from a Mifare Classic NFC tag using an [ODALID](https://odalid.com/fr/) reader.

<p>&nbsp;</p>

## 🛠 Installation

### 🔨 Requirements
To compile this project, you need :
* Visual Studio 2019 or later
* Qt 5.15.2

You need at least the Community (free) edition of Visual Studio.
<br>

### 🔧 Project setup
1. Download this repository
2. Download and install Qt 5.15.2 for MSVC
3. Go to Qt install folder (default : `c:\Qt`) and copy the folder `5.15.2` at the root of the project folder. You should have this file tree :
```
> Qt_NFCReader_GUI
	> .git
	> 5.15.2
		> msvc2019_x64
			> ...
		> sha1s.txt
	> QtNFCReaderGUI
		> ...
	> .gitignore
	> README.md
```
4. Open Visual Studio, go to `Extensions -> Manage extensions -> Online` and install `Qt Visual Studio Tools`

<p>&nbsp;</p>

## 🇫🇷 | 🤔💭 Processus de développement

### 📝 Description du projet
Le but de ce projet était de concevoir une interface graphique permettant de stocker le nom et le prénom d'une personne sur un tag NFC, de pouvoir relire ces informations et d'incrémenter et décrémenter un compteur.
<br>

### 🎨 Design de l'interface
L'interface a été pensée pour être simple et claire.<br>
Seules les actions disponible à un instant T sont affichées et donc utilisables par l'utilisateur. De plus, un emplacement est affiché en permanence pour informer l'utilisateur de l'état du programme. Enfin, des boîtes de dialogue avertissent l'utilisateur des actions importantes effectuées.
<br>

### 🗺️ Organisation du code
Le code de l'application est séparé en deux parties :
* la classe ``QtNFCReaderGUI`` contrôle l'interface utilisateur;
* la classe ``NFCManager`` contrôle la connexion au lecteur NFC et stocke les données de la carte sur l'ordinateur.

L'interface communique avec le code en arrière-plan au moyen de *slots* fournis par Qt et appelés lorsque l'utilisateur interragit avec des éléments : clic sur un bouton, texte modifié...
<br>

### ⌨️ Développement avec Visual Studio
Contrairement à la plupart des projets similaires, celui-ci a été développé sous Visual Studio plutôt qu'avec Qt Creator.<br>
Visual Studio propose en effet plusieurs outils de développement (débogueur, moniteurs de ressources, accès & modification de la mémoire, analyse de code...) plus poussés et plus complets que ceux proposés par Qt Creator. Visual Studio propose aussi de meilleurs outils d'autocomplétion et de vérification d'erreurs.
<br>

### 💢 Problèmes rencontrés
Le principal problème rencontré lors du développement de ce projet a été l'interfaçage avec le lecteur NFC et la carte.<br>
La procédure de connection à la carte est en effet précise et nécessite d'être respectée à la lettre pour fonctionner.