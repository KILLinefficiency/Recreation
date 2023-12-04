import "dart:io";

Set<int> makeSet(String text) {
    return text.split(" ").where((x) => x != "").map((x) => int.parse(x)).toSet();
}

List<String> lines = File("input.txt").readAsStringSync().trim().split("\n");

List<int> getCopy(int index) {
    List<String> tokens = lines[index - 1].split(RegExp(r"[:|]")).map((x) => x.trim()).toList();
    Set<int> winning = makeSet(tokens[1]);
    Set<int> your = makeSet(tokens[2]);
    int won = winning.intersection(your).toList().length;
    return [for(int x = index + 1; x <= won + index; x++) x];
}

void main() {
    int answer = 0;
    List<List<int>> data = [[for(int n = 1; n <= lines.length; n++) n]];
    for(int i = 0; i < data.length; i++) {
        for(int j = 0; j < data[i].length; j++) {
            List<int> copies = getCopy(data[i][j]);
            if(copies.length != 0) {
                data.add(copies);
            }
        }
    }

    for(List<int> each in data) {
        answer += each.length;
    }
    print(answer);
}