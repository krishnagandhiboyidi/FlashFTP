/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package FileServer;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author red_ntry
 */
 public class CLIENTConnection implements Runnable {

  private final Socket clientSocket;
  private BufferedReader in = null;

  public CLIENTConnection(Socket client) {
   this.clientSocket = client;
  }

  @Override
public void run() {
 try {
    in = new BufferedReader(new InputStreamReader(
            clientSocket.getInputStream()));
    String clientSelection;
    while ((clientSelection = in.readLine()) != null) {
        switch (clientSelection) {
            case "1":
                receiveFile();
                break;
            case "2":
                String outGoingFileName;
                while ((outGoingFileName = in.readLine()) != null) {
                    sendFile(outGoingFileName);
                }

                break;
            default:
                System.out.println("Incorrect command received.");
                break;
        }
        in.close();
        break;
    }

     } catch (IOException ex) {
    Logger.getLogger(CLIENTConnection.class.getName()).log(Level.SEVERE, null, ex);
   }
}

    public void receiveFile() {
   try {
     int bytesRead;
     String fileName1;
     String fileName;
       try (DataInputStream clientData = new DataInputStream(clientSocket.getInputStream())) {
           fileName1 = clientData.readUTF();
          fileName="/home/red_ntry/Serverfiles/";
          fileName=fileName+fileName1;
         try (OutputStream output = new FileOutputStream(fileName)) {
             long size = clientData.readLong();
             byte[] buffer = new byte[1024];
             while (size > 0 && (bytesRead = clientData.read(buffer, 0, (int) Math.min(buffer.length, size))) != -1) {
                 output.write(buffer, 0, bytesRead);
                 size -= bytesRead;
             }
         }
          System.out.println("file in which storage took place is :"+fileName);
       }

    System.out.println(fileName1+":named input File "+" received from client.");
} catch (IOException ex) {
    System.err.println("Client error. Connection closed.");
      }
   }

   public void sendFile(String fileName) {
    try {
    //handle file read
    File myFile = new File(fileName);
    byte[] mybytearray = new byte[(int) myFile.length()];

    FileInputStream fis = new FileInputStream(myFile);
    BufferedInputStream bis = new BufferedInputStream(fis);
    //bis.read(mybytearray, 0, mybytearray.length);

    DataInputStream dis = new DataInputStream(bis);
    dis.readFully(mybytearray, 0, mybytearray.length);
    System.out.println("buffered bytes:"+mybytearray.length);
    //handle file send over socket
    OutputStream os = clientSocket.getOutputStream();

    //Sending file name and file size to the server
    DataOutputStream dos = new DataOutputStream(os);
    dos.writeUTF(myFile.getName());
    dos.writeLong(mybytearray.length);
    dos.write(mybytearray, 0, mybytearray.length);
    dos.flush();
    System.out.println("File "+fileName+" sent to client.");
 } catch (Exception e) {
    System.err.println("File does not exist!");
  } }}