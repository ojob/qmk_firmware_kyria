# Comment s'y prendre

## En partant d'une carto simplifiée

D'abord convertir la carto simplifiée

    qmk json2c bépo-jojo.json > partial.c

Puis remplacer la carto dans le fichier c

    vim partial.c keymap.c

## Ou les mains dans le cambouis

Éditer le fihier `keymap.c`

## Mettre en œuvre

1. Installer QMK

       python3 -m venv .env
       activate
       pip install --upgrade pip
       pip install qmk

2. Compiler la carto

       qmk compile -e CONVERT_TO=elite_pi

3. Appui-double sur le bouton de reset du clavier
4. Quand le dossier est monté, envoyer le fichier vers le clavier

       cp splitkb_kyria_rev2_ojob_elite_pi.uf2 /media/joel/RPI-RP2/

5. Brancher l'autre moitié du clavier, faire double-appui sur le bouton de reset
6. Quand le dossier est monté, envoyer le fichier vers cette autre moitié
