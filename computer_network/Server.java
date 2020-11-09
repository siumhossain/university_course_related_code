import java.net.*;  
import java.io.*;  

class MyServer{  
		public static void main(String args[])throws Exception{  
			ServerSocket ss=new ServerSocket(8080);  
			Socket s=ss.accept();  
			DataInputStream din=new DataInputStream(s.getInputStream());  
			DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
			  
			String str="",str2=""; 
			System.out.println("client connect"); 
			while(true){  
				if(str.equals("close")==true || str2.equals("close")==true){
					break;
				}
			str=din.readUTF(); 
			//System.out.println("server start"); 
			System.out.println("client says: "+str);  
			str2=br.readLine();  
			dout.writeUTF(str2);  
			 
			}  
			din.close();  
			s.close();  
			ss.close();  
}
} 
			
