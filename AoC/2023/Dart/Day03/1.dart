import "dart:io";

bool isNumber(String char) {
    return "0123456789".contains(char);
}

bool isSymbol(String char) {
    return !(".0123456789".contains(char));
}

int parseNum(List<String> line, int index) {
    int right = index;
    int left = index - 1;
    List<String> tmp_string = [];
    while(right < line.length && isNumber(line[right])) {
        tmp_string.add(line[right]);
        right++;
    }
    while(left >= 0 && isNumber(line[left])) {
        tmp_string.insert(0, line[left]);
        left--;
    }
    StringBuffer make_string = StringBuffer();
    make_string.writeAll(tmp_string);
    return int.parse(make_string.toString()); 
}

List<List<String>> tokenize(List<String> lines) {
    List<List<String>> all_tokens = [];
    for(String line in lines) {
        all_tokens.add(line.split(""));
    }
    return all_tokens;
}

int play(List<List<String>> tokens) {
    int answer = 0;
    int rows = tokens.length - 1;
    int cols = tokens[0].length - 1;
    int i = 1;
    while(i < rows) {
        int j = 1;
        while(j < cols) {
            if(isSymbol(tokens[i][j])) {
                bool top = false, bottom = false;
                // left
                if(isNumber(tokens[i][j - 1])) {
                    answer += parseNum(tokens[i], j - 1);
                }
                // right
                if(isNumber(tokens[i][j + 1])) {
                    answer += parseNum(tokens[i], j + 1);
                }
                // top
                if(isNumber(tokens[i - 1][j])) {
                    answer += parseNum(tokens[i - 1], j);
                    top = true;
                }
                // bottom
                if(isNumber(tokens[i + 1][j])) {
                    answer += parseNum(tokens[i + 1], j);
                    bottom = true;
                }
                // top-left
                if(isNumber(tokens[i - 1][j - 1]) && !top) {
                    answer += parseNum(tokens[i - 1], j - 1);
                }
                // top-right
                if(isNumber(tokens[i - 1][j + 1]) && !top) {
                    answer += parseNum(tokens[i - 1], j + 1);
                }
                // bottom-left
                if(isNumber(tokens[i + 1][j - 1]) && !bottom) {
                    answer += parseNum(tokens[i + 1], j - 1);
                }
                // bottom-right
                if(isNumber(tokens[i + 1][j + 1]) && !bottom) {
                    answer += parseNum(tokens[i + 1], j + 1);
                }
            }
            j++;
        }
        i++;
    }
    return answer;
}

void main() {
    List<String> data = File("input.txt").readAsStringSync().trim().split("\n");
    List<List<String>> tokens = tokenize(data);
    print(play(tokens));
}