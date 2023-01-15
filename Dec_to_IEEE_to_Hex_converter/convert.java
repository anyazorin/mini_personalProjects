
import java.lang.Integer;
public class convert{
    public static void main(String[] args){
        if(args[0].equals("hex_to_dec")){
            int dec=Integer.parseInt(args[1],16);
            System.out.println(dec);  
        }
        else if(args[0].equals("dec_to_hex")){
            int dec=Integer.parseInt(args[1]);
            System.out.println(Integer.toHexString(dec));  
        }
        else if(args[0].equals("bn_to_dec")){
            int dec=Integer.parseInt(args[1],2);
            System.out.println(dec); 
        }
        else if(args[0].equals("dec_to_bn")){
            int dec=Integer.parseInt(args[1]);
            System.out.println(Integer.toBinaryString(dec));  
        }
        else if(args[0].equals("hex_to_bn")){
            int dec=Integer.parseInt(args[1],16);
            System.out.println(Integer.toBinaryString(dec));
        }
        else if(args[0].equals("bn_to_hex")){
            int dec=Integer.parseInt(args[1],2);
            System.out.println(Integer.toHexString(dec));
        }
        else System.out.println("not valid entry");
    }
    

}