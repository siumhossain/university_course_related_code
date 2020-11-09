import java.net.*;  
import java.io.*;  
class MyClient{  
	public static void main(String args[])throws Exception{  
		Socket s=new Socket("localhost",8080);  
		DataInputStream din=new DataInputStream(s.getInputStream());  
		DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		  
		String str="",str2="";  
		while(true){
		if(str.equals("close")==true || str2.equals("close")==true){
			break;
		}
		str=br.readLine();  
		dout.writeUTF(str);  
		
		str2=din.readUTF();  
		System.out.println("Server says: "+str2);  
		}  
		  
		dout.close();  
		s.close();  
}}

