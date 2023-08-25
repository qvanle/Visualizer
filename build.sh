#! /usr/bin/bash 

Black='\033[0;30m'
Red='\033[0;31m'
Green='\033[0;32m'
Brown='\033[0;33m'
Blue='\033[0;34m'
Purple='\033[0;35m'
Cyan='\033[0;36m'
LightGray='\033[0;37m'
DarkGray='\033[1;30m'
LightRed='\033[1;31m'
LightGreen='\033[1;32m'
Yellow='\033[1;33m'
LightBlue='\033[1;34m'
LightPurple='\033[1;35m'
LightCyan='\033[1;36m'
White='\033[1;37m'
NC='\033[0m'

clear
printf "${LightPurple}do you want to run cmake ?${NC}\n"
read -p "[Y/n] " cmake_status

clear 

if [ "$cmake_status" = "Y" ] || [ "$cmake_status" = "y" ];
then 
    printf "${LightPurple}running cmake${NC}\n}"
    cmake -B build/ -DCMAKE_BUILD_TYPE=Released

    printf "${Yellow}Press any key to continue${NC}"
    read -n 1 -s -r 
    clear 
fi

printf "${LightPurple}running make${NC}\n"
make -C build 

build_status="$?"

printf "${Yellow}Press any key to continue${NC}"
read -n 1 -s -r 
clear 

if [ $build_status -eq 0 ];
then 
    printf "${LightGreen}Build successful${NC}\n"
    #gdb -ex run build/CLM 
    ./build/CLM
else 
    printf "${Red}Build failed\n"
    printf "return value: $build_status\n${NC}"
fi 

printf "${Yellow}Press any key to continue${NC}"
read -n 1 -s -r 
clear

