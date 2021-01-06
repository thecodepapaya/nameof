#!/bin/bash
sudo chmod 755 uninstall_nameof.sh
sudo chmod 755 db-sh-txt
sudo chmod 755 nameof
echo "Giving executable permissions ..."
echo "Creating Directories ..."
sudo mkdir /usr/share/nameof
sudo cp -r . /usr/share/nameof
sudo cp /usr/share/nameof/nameof /usr/local/bin
echo "Successfully copied contents ..."
echo "Successfully Installed database."
echo "run \"nameof <9-digit-ID>\"" 
