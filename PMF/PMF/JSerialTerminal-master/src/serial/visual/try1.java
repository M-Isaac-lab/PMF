package serial.visual;
import serial.visual.*;
import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;
import jssc.SerialPortException;
import jssc.SerialPortList;
import jssc.*;
import java.util.ArrayList;

public class try1 {
	private static SerialPort serialPort;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	//int a = 0;	
		ArrayList<String> cars = new ArrayList<String>();
	//while (true){
		
		//String str = "yaaaa:yesss";
		
		//ArrayList<String> cars = new ArrayList<String>();
		//cars = str.split(":");
		try {
		String buffer = serialPort.readString();
		String bufferString = new String(buffer);
		String[] m = bufferString.split(":");
		
		//String[] m = bufferString.split(":");
		for (String word : m) {
            //System.out.println(word);
            cars.add(word);
            System.out.println(bufferString);
            
            
        }}
		catch(Exception e) {
			
		}
		//System.out.println(cars);
		//cars.clear();
		//System.out.println(cars);
		
		//System.out.println(m);
		

	}
	}
	
//}
	
