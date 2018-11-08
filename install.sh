#!/bin/bash
sudo chmod 755 nameof
sudo mkdir /usr/share/nameof
echo "Created Directories ..."
sudo cp -r . /usr/share/nameof
sudo cp /usr/share/nameof/nameof /usr/local/bin
echo "Successfully copied contents ..."
echo "Successfully Installed database."
echo "run \"nameof <9-digit-ID>\"" 
