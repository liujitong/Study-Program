#include <cstdio>
#include <cmath>

int n = 8;

double** createHilbert(){
	double** temp = new double*[n];
	for (int i = 0; i < n; i++){
		temp[i] = new double[n];
		for (int j = 0; j < n; j++)
			temp[i][j] = 1.0 / (i + j + 1);
	}
	return temp;
}

double* multiply(double** A, double* bl){
	double* ans = new double[n];
	for (int i = 0; i < n; i++){
		ans[i] = 0;
		for (int j = 0; j < n; j++)
			ans[i] += A[i][j] * bl[j];
	}
	return ans;
}

double** Cholesky(double** Hilbert){
	double** L = new double*[n];
	for (int i = 0; i < n; i++)
		L[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			L[i][j] = 0;

	L[0][0] = sqrt(Hilbert[0][0]);
	for (int i = 1; i < n; i++)
		L[i][0] = Hilbert[i][0] / L[0][0];
	for (int j = 1; j < n; j++){
		double ss = 0.0;
		for (int i = 0; i < j; i++)
			ss += L[j][i] * L[j][i];
		L[j][j] = sqrt(Hilbert[j][j] - ss);
		for (int i = j + 1; i < n; i++){
			double s = 0.0;
			for (int ii = 0; ii < j; ii++)
				s += L[i][ii] * L[j][ii];
			L[i][j] = (Hilbert[i][j] - s) / L[j][j];
		}
	}
	return L;
}

double* solve(double** L, double* b){
	double* y = new double[n];
	for (int i = 0; i < n; i++){
		y[i] = b[i] / L[i][i];
		for (int j = 0; j < i; j++)
			y[i] = y[i] - y[j] * L[i][j] / L[i][i];
	}
	return y;
}

double* solve2(double** L, double* y){
	double* x = new double[n];
	for (int i = n-1; i >= 0; i--){
		x[i] = y[i] / L[i][i];
		for (int j = i + 1; j < n; j++)
			x[i] = x[i] - x[j] * L[j][i] / L[i][i];
	}
	return x;
}

double norm(double* A, double* B){
	double mmax = 0.0;
	for (int i = 0; i < n; i++)
		if (fabs(A[i] - B[i]) > mmax) mmax = fabs(A[i] - B[i]);
	return mmax;
}

int main(){
	double** Hilbert = createHilbert();
	double* x0 = new double[n];
	for (int i = 0; i < n; i++) x0[i] = 1;
	double* b = multiply(Hilbert, x0);
	double** L = Cholesky(Hilbert);
	double* y = solve(L, b);
	double* x = solve2(L, y);
	double* r = multiply(Hilbert, x);

	FILE* fp = fopen("test2.txt", "w");
	fprintf(fp, "Jin si jie x:\n");
	for (int i = 0; i < n; i++)
		fprintf(fp, "%f\t", x[i]);
	fprintf(fp, "\n");
	fprintf(fp, "Wu cha fan shu:  %.10f\n", norm(x, x0));
	fprintf(fp, "Can cha fan shu:  %.20f\n", norm(r, b));
	fclose(fp);

	delete[] b;
	delete[] x0;
	delete[] y;
	delete[] x;
	delete[] r;
	for (int i = 0; i < n; i++)
		delete[] Hilbert[i];
	delete[] Hilbert;
	for (int i = 0; i < n; i++)
		delete[] L[i];
	delete[] L;
	return 0;
}
