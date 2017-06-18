#! /bin/sh

sudo apt install git
sudo apt install vim-gnome

# Install Virtualbox
sudo apt install virtualbox

# Install Docker
wget -qO- https://get.docker.com/ | sh
sudo usermod -aG docker $(whoami)
