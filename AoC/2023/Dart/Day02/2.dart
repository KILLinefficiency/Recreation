import "dart:io";

int evaluate(List<String> lines) {
    int answer = 0;
    for(String line in lines) {
        List<String> head = line.split(":");
        int id = int.parse(head[0].split(" ")[1]);
        List<String> games = head[1].split(";");
        Map<String, int> colors = {
            "red": 0,
            "green": 0,
            "blue": 0,
        };
        for(String game in games) {
            List<String> cubes = game.split(",").map((x) => x.trim()).toList();
            for(String cube in cubes) {
                List<String> tokens = cube.split(" ");
                int number = int.parse(tokens[0]);
                if(number > (colors[tokens[1]] ?? 0)) {
                    colors[tokens[1]] = number;
                }
            }
        }
        answer += (colors["red"] ?? 0) * (colors["green"] ?? 0) * (colors["blue"] ?? 0);
    }
    return answer;
}

void main() {
    List<String> data = File("input.txt").readAsStringSync().trim().split("\n");
    print(evaluate(data));
}