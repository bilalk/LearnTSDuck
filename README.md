## TSDuck - The MPEG Transport Stream Toolkit

This library will create learning and testing scenarios of TSDuck for following:

- Transport stream acquisition or transmodulation, including DVB, ATSC, ISDB, ASI and IP multicast.
- Analyze transport streams, PSI/SI signalization, bitrates, timestamps.
- Monitor and report conditions on the stream (video and audio properties, bitrates, crypto-periods, signalization).
- On-the-fly transformation or injection of content and signalization.
- Modify, remove, rename, extract services.
- Work on live transport streams, DVB-S/C/T, ATSC, ISDB-T, ASI, UDP ("IP-TV"), HTTP, HLS, SRT, RIST or offline transport stream files.
- Use specialized hardware such as cheap DVB, ATSC or ISDB tuners (USB, PCI), professional Dektec devices, cheap HiDes modulators, VATek-based modulators (e.g. Suntechtv U3, USB).
- Re-route transport streams to other applications.
- Extract or inject Multi-Protocol Encapsulation (MPE) between TS and UDP/IP.
- Analyze and inject SCTE 35 splice information.
- Extract specific encapsulated data (Teletext, T2-MI).
- Emulate a CAS head-end using DVB SimulCrypt interfaces to and from ECMG or EMMG.
- And more...


Currently this repository is under development for learning purposes.
To run this on Linux/Ubuntu following commands to be executed.
Note: only run for first time for installing library and repo.

su root

sudo apt install libsrt1.4-openssl

sudo apt --fix-broken install

sudo dpkg -i tsduck_3.32-2983.debian11_amd64.deb

sudo dpkg -i tsduck-dev_3.32-2983.debian11_amd64.deb

mkdir tsduck

cd tsduck

sudo apt install git

git clone https://github.com/bilalk/LearnTSDuck.git

cd tsduck

scripts/install-prerequisites.sh

which tsp

tsp –version


ls /usr/bin/make

sudo apt-get update

sudo apt-get install -y make 

sudo apt-get install python

sudo apt-get install build-essential

sudo make install

sudo make installer

sudo make -j10

source scripts/setenv.sh

make test


//Successful installation



### --- For updating libs

After each edit run following on main learnTSDuck folder.

sudo make

source scripts/setenv.sh

### ---- For running code locally

cd /sample/sample-app-custom/

make

./myexec

### ---- For running code on live debain VM

1- connect with RDP 

44.212.99.118

usr/pwd = admin/admin123

2- goto zaktest folder. Run the below commands for all the scenarios. Change the scenario_name to (scenario1, scenario2, sccenario3) and test_file_name to the cpp file of that scenario.

cd scenario_name

make

./test_file_name

3- Compare results with tsanalyze




