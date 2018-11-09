<h1> Interpreteur de Commandes : Gestion Table de Donnee </h1>
DUT Paris Descartes Projet 
<h2> Pour Demarrer </h2>
<h3> Langage </h3>
<ul>
  <li> C (Sans POO)
  <ul>
    <li> Utilsation des structures de données </li>
    <li> Utilsation des  pointeurs </li>
    </ul>
  </li>
  </ul>
<h3> Prerequis </h3>
<ul><li> Visual Studio version 2015 ou ulterieurs</li></ul>

<h2> Présentation </h2>
Nous avions pour but de créer un programme pouvant créer et gérer une table de données. Le programme devait pouvoir interpréter des commandes afin d’afficher, de créer, modifier ou supprimer une table de donnée et enregistrement. Pour ce faire nous devions créer sept commandes. Trois d’entre elles servent à créer, afficher et supprimer une table. quatre d’entre elles servent à insérer des données dans une table, supprimer des données, en sélectionner et afficher un ou tous les enregistrements. 

<h2> Les Fonctionnalitées </h2>
La première fonction de création d’une table doit permettre de créer une table comportant un certain nombre de champs et nom et types différents. La commande s’écrit sous la forme : 
#### Create_table Nomdelatable Nbdechamps Nomduchamp1 Typeduchamp1 Nomduchamp2 Typeduchamp2

La seconde fonction doit simplement permettre de supprimer une table de donnée. La commande s’écrit sous la forme :
#### Delete_table Nomdelatable

La fonction suivante doit permettre d’afficher une table en affichant les champs avec leurs noms et type de données. Le commande s’écrit sous la forme :
#### Afficher_schema Nomdelatable

La quatrième fonction doit permettre d’insérer un enregistrement contenant des données pour chaque champ en fin de table. La commande s’écrit sous la forme :                         
#### Insert_enregistrement Nomdelatable Datachamp1 Datachamp2

La cinquième doit permettre d’afficher une ligne de donnée en fonction du numéro d’enregistrement entré. La commande s’écrit: 
#### Afficher_enregistrement Nomdelatable Numenregistrement

La fonction suivante doit elle aussi afficher des données mais cette fois elle doit toute les affichées. La commande s’écrit: 
#### Afficher_enregistrements Nomdelatable

Enfin, la dernière commande doit permettre à l’utilisateur de supprimer une ligne d’enregistrement dans une table. Elle s’écrit: 
#### Delete_enregistrement Nomdelatable Numenregistrement

<h2> Auteur </h2>
Rani Kharsa 
