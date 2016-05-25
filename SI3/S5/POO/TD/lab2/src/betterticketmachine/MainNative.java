package betterticketmachine;

public class MainNative {
	
	public static void main(String[] args){
		TicketMachine machine = new TicketMachine(30);
		System.out.println(machine.getPrice());
	}

}
