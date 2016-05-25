package labclasses;

/** @author:Karim **/

public class Main {
	
	public static void main (String[] args){
		
		/*This main code will create a labClass, create two students, 
		 * insert their informations and add them to the lab class.
		 * Finally the class will add different informations
		 * about the labclass (instructor / room / time)
		 */
		
		LabClass lab = new LabClass(10);
		Student stud1 = new Student("Joe Dalton","123");
		Student stud2 = new Student("Timothy Dalton","456");
		
		stud1.addCredits(6);
		stud2.addCredits(4);
		
		
		
		lab.enrollStudent(stud1);
		lab.enrollStudent(stud2);
		
		stud1.print();
		stud2.print();
		
		lab.setInstructor("Toto Sama");
		lab.setRoom("404");
		lab.setTime("Monday , 6am");

	}

}
