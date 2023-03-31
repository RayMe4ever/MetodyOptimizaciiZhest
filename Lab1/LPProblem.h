#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

class LPProblem {
public:

	LPProblem(vector<double>& f_coeffs, vector<vector<double>>& r_matrix, vector<double>& r_vector, vector<int>& sign, vector<int>& r_signs, bool con) {
		var_num = f_coeffs.size();
		fun_coeffs = f_coeffs;
		res_num = r_vector.size();
		res_matrix = r_matrix;
		res_vector = r_vector;
		signs = sign;
		res_signs = r_signs;
		cond = con;
		condChange = false;
	}

	void print(); // ������� ������ � �������

	void to_canonical_form(); // ������������ ������ � ������������ �����

	LPProblem* dual(); // ���������� ����� ������ - ������������ � ������

	vector<double> simplex_method2(vector<double>& sol);
	vector<double> simplex();

	vector<double> extreme_point_enum(); // ������ ������ ������� �������� ������� �����

	vector<double> direct_by_dual(vector<double>& sol);

	void matrix_print(vector<vector<double>>& a);
	void vector_print(vector<double>& v);

	double obj_fun(vector<double> x) {
		double sum = 0;
		for (int i = 0; i < var_num; i++) {
			sum += x[i] * fun_coeffs[i];
		}
		return condChange ? -sum : sum;
	}
private:
	static vector<double> gauss(vector<vector<double>>& A, vector<double>& Y, int n);
	vector<vector<double>> inverse_matrix(vector<vector<double>>& A);
	// ���������� ����������
	int var_num;
	// ������������ ������� �������
	vector<double> fun_coeffs;
	// ���������� �����������
	int res_num;
	// ������� ������������� �����������
	vector<vector<double>> res_matrix;
	// ������ ������-������� �����������
	vector<double> res_vector;
	// ����� � ����������� (0 ��� '=', 1 ��� '<=', 2 ��� '>=')
	vector<int> signs;
	// ����������� �� ���� (0 - ���, 1 - '>= 0', 2 - '<= 0')
	vector<int> res_signs;
	// ������� ������ (0 - ����������� ��, 1 - ������������ ��)
	bool cond;
	// �������� �� ������� ������
	bool condChange;
};