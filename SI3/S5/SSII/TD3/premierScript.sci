//Récupérer le contenu d'un fichier en décimal, binaire et en chaîne de caractère
	public static byte[] getContenu(File f) throws IOException {
		byte[] lignes = new byte[(int) f.length()];
		String ligne;

		InputStream ips = new FileInputStream(f);
		InputStreamReader ipsr = new InputStreamReader(ips);
		BufferedReader br = new BufferedReader(ipsr);

		while ((ligne = br.readLine()) != null) {
			lignes = ligne.getBytes("UTF-8");
		}
		//Fermeture du bufferReader afin de libérer des ressources qui lui sont confiées
		br.close();

		return lignes;
	}