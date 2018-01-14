# FlashFTP
This project is a basic version of FTP in which there is an inclusion of single file download,upload(File with any extension).
Single user access is provided with following credentials
     username:'asd'
     password:'123'
     IP:'Public'
     port:'80'
User is allowed to have access on attributes or Functionalities like 
    --Browsing one's own local machine.
    --Uploading a file(any format) to a remote machine(acting as a server).
    --Downloading a file(any format) from a remote machine (acting as a server).
In prior,run server program (FileServer/src/FileServer/FileServer.java),Whose execution further leads to execution of a thread.
While the execution of client side starts from (FLASHFTP/src/flashftp/userframe.java)
--user has to be clear enough in maintaining IP of the remote server which he wish to connect to(FLASHFTP/src/flashftp/FileClient.java).
--One should also take care of paths(we use to download,upload).
