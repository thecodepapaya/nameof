#! /bin/bash

choice="n"
read -p "Do you really want to remove name identifier tool, write \"y\" for yes and \"n\" for no: " choice

if [[ "$choice" == "y" ]] || [[ "$choice" == "Y" ]];
then
path=$(pwd)
rmpath=$(sudo rm -r $path)
    if sudo rm -r /usr/share/nameof && sudo rm /usr/local/bin/nameof && $rmpath  ;then
        echo "successfully uninstalled the \"nameof\" tool , use \"sudo apt autoremove;sudo apt autoclean\" for removing traces and free up memory"
    else
        echo "Error deleting the \"nameof\" tool "
        exit 6
    fi
else
    echo "Aborted"
fi
