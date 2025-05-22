#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Report {
    int subjective_points, objective_points, agg_score;
    void input() { cin >> subjective_points >> objective_points >> agg_score; }
};

struct ReportCard {
    int student_Id;
    string student_name, student_sex;
    Report s_langugae, s_math, s_english, s_science;
    void input() {
        cin >> student_Id >> student_name >> student_sex;
        s_langugae.input();
        s_math.input();
        s_english.input();
        s_science.input();
    }
    void print_short() {
        cout << student_name << " " << s_langugae.agg_score << " "
             << s_math.agg_score << " " << s_english.agg_score << " "
             << s_science.agg_score << endl;
    }
    void print_long() {
        cout << student_Id << " " << student_name << " " << student_sex << " "
             << s_langugae.agg_score << " " << s_math.agg_score << " "
             << s_english.agg_score << " " << s_science.agg_score << endl;
    }
} student[5];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ReportCard student1, student2, student3;
    // 赋值初始化
    student1.student_Id = 1001;
    student1.student_name = "张三";
    student1.student_sex = "男";
    student1.s_langugae.agg_score = 80;
    student1.s_math.agg_score = 95;
    student1.s_english.agg_score = 90;
    student1.s_science.agg_score = 92;
    // 列表初始化
    student2 = (ReportCard){1002,
                            "李四",
                            "男",
                            (Report){40, 20, 60},
                            (Report){30, 40, 70},
                            (Report){40, 40, 80},
                            (Report){30, 59, 89}};
    // 拷贝初始化
    student3 = student1;
    student2.print_short();
    student3.print_short();
    for (int i = 0; i < 5; i++) {
        student[i].input();
    }
    cout << "学号 姓名 性别 语文 数学 英语 科学" << endl;
    for (int i = 0; i < 5; i++) {
        student[i].print_long();
    }
    return 0;
}
