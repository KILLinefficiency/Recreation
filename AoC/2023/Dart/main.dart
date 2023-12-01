import "dart:io";

bool isNum(String char) {
    bool check = false;
    for(int i = 0; i < 11; i++) {
        check = check || (char == i.toString());
    }
    return check;
}

void main() {
    List<String> values = File("input.txt").readAsStringSync().trim().split("\n");
    List<int> digits = [];
    for(String val in values) {
        StringBuffer number = StringBuffer();
        for(int i = 0; i < val.length; i++) {
            if(isNum(val[i])) {
                number.write(val[i]);
                break;
            }
        }
        for(int j = val.length - 1; j >= 0; j--) {
            if(isNum(val[j])) {
                number.write(val[j]);
                break;
            }
        }
        digits.add(int.parse(number.toString()));
    }
    int answer = digits.reduce((x, y) => x + y);
    print(answer);
}