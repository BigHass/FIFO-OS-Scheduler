//Authors: Husni Abdelsalam Husni Abed
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Process {
	string p_name;
	int arr_t{};//arrival time
	int proc_t{};//processing time
	int res_t{};//response
	int turnaround{};//turnaround
	int delay{};//delay
	int start_t{};//starting time
	int comp_t{};//Completion time
}; vector<Process>procList;
int totalturnaround = 0, totaldelay = 0;
double avgturnaround, avgdalay;
void ReadData() { //To load data from the text file. please put the the text file which contain the sample input in the resource file at project folder
	string p_name;
	int arr_t;
	int proc_t;
	ifstream datafile;
	datafile.open("in.txt", ios::in);
	int NumOfprocesses;
	datafile >> NumOfprocesses;
	if (datafile.is_open()) {
		for (int i = 0; i < NumOfprocesses; i++) {
			procList.push_back(Process());
			datafile >> p_name;
			procList[i].p_name = p_name;
			datafile >> arr_t;
			procList[i].arr_t = arr_t;
			datafile >> proc_t;
			procList[i].proc_t = proc_t;
		}
		datafile.close();
	}
}

void WriteData() {//to write the result on the file .txt, please open the project folder to show the file.txt after run of code  
	string s = "";
	fstream MyResult;
	MyResult.open("out.txt", ios::out);
	if (MyResult.is_open()) {
		for (int i = 0; i < procList.size(); i++)
		{
			s += procList[i].p_name;
		}
		s += '\n';
		MyResult << s;
		for (int i = 0; i < procList.size(); i++)
		{
			MyResult << procList[i].p_name + ":" + "(response=" + to_string(procList[i].res_t) + ", turnaround=" + to_string(procList[i].turnaround) + ", delay=" + to_string(procList[i].delay) + ")" + '\n';

		}
		MyResult << "Total Turnaround: " + to_string(totalturnaround) + '\n' + "Total delay: " + to_string(totaldelay) + '\n' + "Average turnaround: " + to_string(avgturnaround) + '\n' + "Average delay: " + to_string(avgdalay) + '\n';
		MyResult.close();
	}

}

bool OrderingProcesses(struct Process p1, struct Process p2) {//To order arrival time values for processes
	if (p1.arr_t< p2.arr_t)
		return true;
	return false;
}

void SortingProcesses() {
	sort(procList.begin(), procList.end(), OrderingProcesses);//to sorting the process depend on the value of arrival time for each process
}

void Calculation() {
	for (int i = 0; i < procList.size(); i++)
	{
		if (i == 0) {
			procList[i].start_t = procList[i].arr_t;//calculate the starting time for first process 
		}
		else {
			procList[i].start_t = max(procList[i].arr_t, procList[i - 1].comp_t);//calculate the starting time for other process 
		}
		procList[i].comp_t = procList[i].start_t + procList[i].proc_t;//calculate the completion time for each process
		procList[i].turnaround = procList[i].comp_t - procList[i].arr_t;//calculate the turnaround time for each process
		procList[i].delay = procList[i].turnaround - procList[i].proc_t;//calculate the waiting time or the delay for each process
		procList[i].res_t = procList[i].delay;//calculate the response time for each process
		totalturnaround += procList[i].turnaround;
		totaldelay += procList[i].delay;
	}
	avgturnaround = double(totalturnaround) / procList.size();
	avgdalay = double(totaldelay) / procList.size();
}

void Display() {//to show the result terminally
	for (int i = 0; i < procList.size(); i++)
	{
		cout << procList[i].p_name;
	}
	cout << endl;
	for (int i = 0; i < procList.size(); i++)
	{
		cout << procList[i].p_name << ":" << "(response=" << procList[i].res_t << ", turnaround=" << procList[i].turnaround << ", delay=" << procList[i].delay << ")" << endl;
	}

	cout << "Total Turnaround: "<<totalturnaround<<'\n'<<"Total delay: "<<totaldelay<<'\n'<<"Average turnaround: "<<avgturnaround<<'\n'<<"Average delay: "<< avgdalay<<endl;
}

int main() {
	ReadData();
	SortingProcesses();
	Calculation();
	WriteData();
	Display();//Option part
	return 0;
}