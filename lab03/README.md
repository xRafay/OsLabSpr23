# OsLabSpr23
To Set static ip: 
open net plan and statically set the ip address and change dchp4 to "NO",gateways,addresses which you want to enter then write command "netplan apply".
![Screenshot from 2023-02-10 23-57-44](https://user-images.githubusercontent.com/123715905/218242383-88cbd403-d78d-438a-866a-b7c683313704.png)

![Screenshot from 2023-02-10 23-58-12](https://user-images.githubusercontent.com/123715905/218242326-5954bd1e-a1ca-4b16-92b8-7cb66bb5163a.png)
![Screenshot from 2023-02-10 23-59-00](https://user-images.githubusercontent.com/123715905/218242334-ad7d0d1e-d8cd-43b5-bce1-48159546f37a.png)
![Screenshot from 2023-02-11 00-13-16](https://user-images.githubusercontent.com/123715905/218242337-37f37a13-011b-48f4-9ad6-f9e58d8cde77.png)
now INSTALLING SAMBA:
1. To install SAMAB on your Ubuntu use the following command
sudo apt install samba –y
2. After installing check SAMBA stsus using the following command
sudo systemctl status smbd
This will show that your SAMBA server is active/running.
3. Now create a directory that will be shared across platforms
mkdir /home/seed/sharingFolder

(Note: Please use your username file creating a directory. My username was seed)
4. Now give permissions to the above directory named sharingFolder
chmod 777 /home/seed/sharingFolder

5. Now create a SAMBA side user to access the directory
sudo useradd user1

6. Now set SAMBA user password

Sudo ambpasswd –a user

![Screenshot from 2023-02-11 00-44-10](https://user-images.githubusercontent.com/123715905/218244144-9217d908-964e-4a1d-a6ac-fe26654ab414.png)
![Screenshot from 2023-02-11 00-49-49](https://user-images.githubusercontent.com/123715905/218244145-3021f55b-3390-4c72-959e-d8c0d94cb853.png)
![Screenshot from 2023-02-11 01-20-12](https://user-images.githubusercontent.com/123715905/218244149-71700fef-b550-40c0-b1ed-cf3f08ceeea2.png)
![Screenshot from 2023-02-11 01-20-51](https://user-images.githubusercontent.com/123715905/218244150-5418fcdb-8a83-4deb-8c32-a7f5e1cac963.png)
![Screenshot from 2023-02-11 01-26-50](https://user-images.githubusercontent.com/123715905/218244151-9ec2af86-d05d-498d-a0b6-0e1e2556f822.png)



