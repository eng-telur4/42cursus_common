#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free -m | grep 'Mem' | awk '{print $2}')
ram_use=$(free -m | grep 'Mem' | awk '{print $3}')
ram_percent=$(free -m | grep 'Mem' | awk '{printf("%.2f\n", $3 / $2 * 100)}')

# DISK
disk_total=$(df -BM --total | awk 'END {print $2}')
disk_use=$(df -BM --total | awk 'END {print $3}')
disk_percent=$(df -BM --total | awk 'END {print $5}')

# CPU LOAD
cpu_fin=$(vmstat 1 2 | tail -1 | awk '{printf("%.1f\n"), 100 - $15}')

# LAST BOOT
lb=$(who -b | grep system | awk '{print $3, $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(echo $(ip addr | grep -1 link/ether | grep inet) | awk -F "[ /]" '{print $2}')
mac=$(echo $(ip addr | grep link/ether) | awk '{print $2}')
# ip=$(hostname -I | grep -oP '(\d+\.\d+\.\d+\.\d+)')
# mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall "#Architecture: $arch
	#CPU physical: $cpuf
	#vCPU: $cpuv
	#Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	#Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	#CPU load: $cpu_fin%
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $tcpc ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmnd cmd"
