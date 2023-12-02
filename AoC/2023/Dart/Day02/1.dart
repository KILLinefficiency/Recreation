import "dart:io";

int evaluate(List<String> lines) {
    int answer = 0;
    for(String line in lines) {
        bool possible = true;
        List<String> head = line.split(":");
        int id = int.parse(head[0].split(" ")[1]);
        List<String> games = head[1].split(";");
        for(String game in games) {
            List<String> cubes = game.split(",").map((x) => x.trim()).toList();
            for(String cube in cubes) {
                List<String> tokens = cube.split(" ");
                int number = int.parse(tokens[0]);
                if(tokens[1] == "red" && number > 12)        { possible = false; }
                else if(tokens[1] == "green" && number > 13) { possible = false; }
                else if(tokens[1] == "blue" && number > 14)  { possible = false; }
            }
        }
        if(possible) {
            answer += id;
        }
    }
    return answer;
}

void main() {
    List<String> data = File("input.txt").readAsStringSync().trim().split("\n");
    print(evaluate(data));
}