import java.util.*;
import javax.crypto.*;
import java.io.*;
import java.security.*;
import java.util.Base64;

class DES {
    public static void main(String args[]) throws Exception {
        String message = "kill him tomorrow.";
        byte[] myMessage = message.getBytes();

        KeyGenerator Mygenerator = KeyGenerator.getInstance("DES");
        SecretKey myDesKey = Mygenerator.generateKey();

        Cipher myCipher = Cipher.getInstance("DES");

        myCipher.init(Cipher.ENCRYPT_MODE, myDesKey);
        byte[] myEncryptedBytes = myCipher.doFinal(myMessage);

        myCipher.init(Cipher.DECRYPT_MODE, myDesKey);
        byte[] myDecryptedBytes = myCipher.doFinal(myEncryptedBytes);

        String encrypteddata = Base64.getEncoder().encodeToString(myEncryptedBytes);
        String decrypteddata = new String(myDecryptedBytes);

        System.out.println("Message    : " + message);
        System.out.println("Encrypted  : " + encrypteddata);
        System.out.println("Decrypted  : " + decrypteddata);
    }
}
