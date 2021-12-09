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

<p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>

## 🇫🇷 | 🤔💭 Processus de développement

### 📝 Description du projet
Le but de ce projet était de concevoir une interface graphique permettant de stocker le nom et le prénom d'une personne sur un tag NFC, de pouvoir relire ces informations et d'incrémenter et décrémenter un compteur.
<br><br>

### 🎨 Design de l'interface
L'interface a été pensée pour être simple et claire.<br>
Seules les actions disponibles à un instant T sont affichées et donc accessibles par l'utilisateur. De plus, un emplacement est affiché en permanence pour informer l'utilisateur de l'état du programme. Enfin, des boîtes de dialogue avertissent l'utilisateur des actions importantes effectuées :
| Ecran de connexion | Ecran principal | Exemple de boîte de dialogue |
| ------------------ | --------------- | ---------------------------- |
| ![image](https://user-images.githubusercontent.com/39455111/145052920-f345b07b-0481-4ab7-9bec-fd9869d36d93.png) | ![image](https://user-images.githubusercontent.com/39455111/145054541-3ffcc49f-e2c2-4d00-9343-8aaa28782cf2.png) | ![image](https://user-images.githubusercontent.com/39455111/145054882-c5bb36f4-3943-4b69-93fa-138a8c551bd3.png) |

*<p align="center">Cliquez sur une image pour l'agrandir</p>*
<br><br>

### 🗺️ Organisation du code
Le code de l'application est séparé en deux classes :
* ``QtNFCReaderGUI``;
* ``NFCManager``.

``QtNFCReaderGUI`` est la clase qui contrôle l'interface utilisateur. C'est elle qui gère par exemple les évènements utilisateurs, tels que l'appui sur un bouton ou la modification d'un champ texte. Pour cela, elle reçoit des signaux provenant de l'interface, appelés *slots* et proposés par Qt. Chaque *slot* est une fonction C++ et il y a un ou plusieurs *slots* par élément interractif (bouton, champ texte...) : on peut donc effectuer une action spécifique en réponse à une interraction particulière avec l'interface. Par exemple, l'appui sur le bouton "Connect" sur l'écran de connexion permet d'appeler la fonction en charge de lancer la connexion au lecteur et modifier un champ texte met à jour l'interface pour mettre l'indicateur de synchronisation en rouge et indiquer à l'utilisateur que les données stockées sur la carte NFC diffèrent de celles affichées à l'écran. C'est donc un modèle MVC avec ``QtNFCReaderGUI`` en tant que contrôleur et l'interface en tant que vue.

``NFCManager`` est la classe qui gère l'interfaçage avec le lecteur NFC :
* connexion
* lecture
* écriture
* incrément
* décrément
* sauvegarde
* restauration
* gestion des erreurs

<br>

### ⌨️ Développement avec Visual Studio
Contrairement à la plupart des projets similaires, celui-ci a été développé sous Visual Studio plutôt qu'avec Qt Creator.<br>
Visual Studio propose en effet plusieurs outils de développement (débogueur, moniteurs de ressources, accès & modification de la mémoire, analyse de code...) plus poussés et plus complets que ceux proposés par Qt Creator. Visual Studio propose aussi de meilleurs outils d'autocomplétion (Intellisense) et de vérification d'erreurs.
<br><br>

### 💢 Problèmes rencontrés
Le principal problème rencontré lors du développement de ce projet a été l'interfaçage avec le lecteur NFC et la carte. La procédure de connection à la carte est en effet précise et nécessite d'être respectée à la lettre pour fonctionner.<br>
L'installation de Qt pour fonctionner avec Visual Studio demande quelques étapes supplémentaires par rapport à l'utilisation de l'IDE Qt Creator fourni et installé avec Qt. Cependant, Qt est très bien intégré à Visual Studio grâce à l'extension Qt VS Tools installable en quelques clics.