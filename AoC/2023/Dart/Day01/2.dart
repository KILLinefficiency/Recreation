import "dart:io";

class Index {
    int index;
    Index(this.index);
}

bool isNum(String char) {
    bool check = false;
    for(int i = 0; i < 11; i++) {
        check = check || (char == i.toString());
    }
    return check;
}

bool match(String text, String pattern, Index idx) {
    int t_len = text.length;
    int p_len = pattern.length;

    int end = idx.index + p_len;
    if(end > t_len) {
        return false;
    }

    String extracted = text.substring(idx.index, end);
    bool matched = pattern == extracted;
    if(matched) {
        idx.index += p_len - 1;
    }
    return matched;
}

String matchAlphas(String text, Index i) {
        if     (match(text, "one",   i)) { return "1"; }
        else if(match(text, "two",   i)) { return "2"; }
        else if(match(text, "three", i)) { return "3"; }
        else if(match(text, "four",  i)) { return "4"; }
        else if(match(text, "five",  i)) { return "5"; }
        else if(match(text, "six",   i)) { return "6"; }
        else if(match(text, "seven", i)) { return "7"; }
        else if(match(text, "eight", i)) { return "8"; }
        else if(match(text, "nine",  i)) { return "9"; }
        return "";
}

List<String> getNums(String text) {
    Index i = Index(0);
    List<String> numbers = [];
    while(i.index < text.length) {
        if(isNum(text[i.index])) {
            numbers.add(text[i.index]);
            i.index++;
        }
        else {
            String aNum = matchAlphas(text, i);
            if(aNum != "") {
                numbers.add(aNum);
            }
            else {
                i.index++;
            }
        }
    }
    return numbers;
}

void main() {
    List<String> values = File("input.txt").readAsStringSync().trim().split("\n");
    int answer = 0;
    print("debug: " + getNums("eightwothree").toString());
    for(String val in values) {
        StringBuffer number = StringBuffer();
        List<String> n = getNums(val);
        number.writeAll([n[0], n[n.length - 1]]);
        answer += int.parse(number.toString());
    }
    print(answer);
}