# OSのアーキテクチャとカーネルのバージョン
ARCH=`uname -a`
# 物理プロセッサの数
CPU=`fgrep 'physical id' /proc/cpuinfo | sort -u | wc -l`
# 仮想プロセッサの数
vCPU=`fgrep 'processor' /proc/cpuinfo | wc -l`
# サーバで現在使用可能なRAMとその使用率
UMEM=`free -m | grep 'Mem' | awk '{print $3}'`
AMEM=`free -m | grep 'Mem' | awk '{print $2}'`
MEMPER=`free -m | grep 'Mem' | awk '{print $3 / $2 * 100}'`
# サーバで現在使用可能なストレージとその使用率
UDSC=`df -m | grep '/home' | awk '{print $3 / 1000}'`
ADSC=`df -m | grep '/home' | awk '{print $2 / 1000}'`
DSCPER=`df -m | grep '/home' | awk '{print $3 / $2 * 100}'`
# 現在のプロセッサの使用率
CPUL=`vmstat | sed -n 3p | awk '{print 100 - $15}'`
# 最後に再起動した日時
DATE=$(last reboot --time-format iso | sed -n 1p | awk '{print $5}' | cut -d 'T' -f 1)
TIME=$(last reboot --time-format iso | sed -n 1p | awk '{print $5}' | cut -d 'T' -f 2 | head -c 5)
LREBOT="${DATE} ${TIME}"
# LVMがアクティブかどうか
LVMU=$(lvdisplay | grep 'LV Status' | uniq | awk '{print $3}')
if [ "${LVMU}" = "available" ]; then
    LVM="yes"
else
    LVM="no"
fi
# アクティブな接続数
CONTCP=`netstat | grep -A 2 'Foreign' | sed -e 1d | grep 'ESTABLISHED' | wc -l`
# サーバを使用しているユーザ数
ULOG=`who | awk '{print $1}' | uniq | wc -l`
# サーバのIPv4アドレスとMACアドレス
IPADDR=`ip addr | grep -w 'inet' | grep -v '127' | cut -d ' ' -f 6 | cut -d '/'     -f 1`
MACADDR=`ip addr | grep -B 1 ${IPADDR} | sed -n 1p | awk '{print $2}'`
# sudoで実行されたコマンドの数
# todo
SUDO=""

# ========== ========== ========== ========== ==========
# OUTPUT
# ========== ========== ========== ========== ==========
echo "#Architecture: ${ARCH}"
echo "#CPU physical : ${CPU}"
echo "#vCPU : ${vCPU}"
echo "#Memory Usage: ${UMEM}/${AMEM}MB (${MEMPER}%)"
echo "#Disk Usage: ${UDSC}/${ADSC}Gb (${DSCPER}%)"
echo "#CPU load: ${CPUL}%"
echo "#Last boot: ${LREBOT}"
echo "#LVM use: ${LVM}"
echo "#Connections TCP : ${CONTCP} ESTABLISHED"
echo "#User log: ${ULOG}"
echo "#Network: IP ${IPADDR} (${MACADDR})"
echo "#Sudo : ${SUDO} cmd"
