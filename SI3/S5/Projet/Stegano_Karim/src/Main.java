import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		File f = new File("./Test.txt");

		byte[] cont;
		try {
			cont = getContenu(f);

			afficherContenu(cont);
			byte[] newCont = modifierFichier(cont);
			creerFichierMod(newCont);

			creerFichier();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	//R�cup�rer le contenu d'un fichier en d�cimal, binaire et en cha�ne de caract�re
	public static byte[] getContenu(File f) throws IOException {
		byte[] lignes = new byte[(int) f.length()];
		String ligne;

		InputStream ips = new FileInputStream(f);
		InputStreamReader ipsr = new InputStreamReader(ips);
		BufferedReader br = new BufferedReader(ipsr);

		while ((ligne = br.readLine()) != null) {
			lignes = ligne.getBytes("UTF-8");
		}
		br.close();

		return lignes;
	}

	public static void afficherContenu(byte[] contenu) {
		System.out.println("Affichage du contenu du fichier : ");
		System.out.println("Caractère -> Décimal -> Binaire \n");
		for (byte b : contenu) {
			System.out.println((char) b + "-> " + b + "-> "
					+ Integer.toBinaryString(b));
		}
		System.out.println("Fin de lecture \n");
	}

	//Cr�er fichier texte contenu une cha�ne de caract�re
	public static void creerFichier() throws IOException {
		File file = new File("./Test2.txt");
		String content = "Nouveau texte dans nouveau fichier";

		// if file doesn't exists, then create it
		if (!file.exists()) {
			file.createNewFile();
		}

		FileWriter fw = new FileWriter(file.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);
		bw.write(content);
		bw.close();
		System.out.println("Fichier cr��");

	}
	
	//R�cup�rer le contenu d'un fichier en d�cimal et cr�� un fichier
	public static void creerFichierMod(byte[] cont) throws IOException {
		File file = new File("./testMod.txt");
		String content = "";

		for (byte b : cont) {
			content += (char) b;
		}

		FileWriter fw = new FileWriter(file.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);
		bw.write(content);
		bw.close();
		System.out.println("Fichier modifi� cr��");
	}
	
	//R�cuperer un tableau de d�cimaux et modifier le contenu
	public static byte[] modifierFichier(byte[] contenu) {
		int i = 0;
		System.out.println("D�but de la modification");
		for (byte b : contenu) {
			b += 10;
			contenu[i] = b;
			i++;
			System.out.println((char)b);
		}
		System.out.println("Fin de la modification");
		return contenu;
		
		
	}
		
}