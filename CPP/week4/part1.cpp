Complex &operator=(string str) {
	int pos = str.find("+", 0);
	string sTmpReal = str.substr(0, pos);
	r = atof(sTmpReal.c_str());

	string sTmpImage = str.substr(pos+1, str.length()-pos-2);
	i = atof(sTmpImage.c_str());

	return *this;
}