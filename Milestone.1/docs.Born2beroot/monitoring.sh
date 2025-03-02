#!/bin/bash

# The architecture of your operating system and its kernel version.
arch=$(uname -a)

# The number of physical processors.
cpuf=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

# The number of virtual processors.
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# The current available RAM on your server and its utilization rate as a percentage.
ram_total=$(free -m | grep 'Mem' | awk '{print $2}')
ram_use=$(free -m | grep 'Mem' | awk '{print $3}')
ram_percent=$(free -m | grep 'Mem' | awk '{printf("%.2f\n", $3 / $2 * 100)}')

# The current available storage on your server and its utilization rate as a percentage.
disk_total=$(df -BM --total | awk 'END {print $2}')
disk_use=$(df -BM --total | awk 'END {print $3}')
disk_percent=$(df -BM --total | awk 'END {print $5}')

# The current utilization rate of your processors as a percentage.
cpu_fin=$(vmstat 1 2 | tail -1 | awk '{printf("%.1f\n"), 100 - $15}')

# The date and time of the last reboot.
lb=$(who -b | grep system | awk '{print $3, $4}')

# Whether LVM is active or not.
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# The number of active connections.
tcpc=$(ss -ta | grep ESTAB | wc -l)

# The number of users using the server.
ulog=$(users | wc -w)

# The IPv4 address of your server and its MAC (Media Access Control) address.
ip=$(echo $(ip addr | grep -1 link/ether | grep inet) | awk -F "[ /]" '{print $2}')
mac=$(echo $(ip addr | grep link/ether) | awk '{print $2}')
# ip=$(hostname -I | grep -oP '(\d+\.\d+\.\d+\.\d+)')
# mac=$(ip link | grep "link/ether" | awk '{print $2}')

# The number of commands executed with the sudo program.
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
