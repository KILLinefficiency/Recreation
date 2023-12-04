import "dart:io";
import "dart:math";

Set<int> makeSet(String text) {
    return text.split(" ").where((x) => x != "").map((x) => int.parse(x)).toSet();
}

void main() {
    int answer = 0;
    List<String> lines = File("input.txt").readAsStringSync().trim().split("\n");
    for(String line in lines) {
        List<String> tokens = line.split(RegExp(r"[:|]")).map((x) => x.trim()).toList();
        Set<int> winning = makeSet(tokens[1]);
        Set<int> your = makeSet(tokens[2]);
        Set<int> wins = winning.intersection(your);
        int points = (wins.length > 0) ? pow(2, wins.length - 1).toInt() : 0;
        answer += points;
    }
    print(answer);
}