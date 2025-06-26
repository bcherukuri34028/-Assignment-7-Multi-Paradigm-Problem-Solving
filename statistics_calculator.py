from collections import Counter

class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = sorted(numbers)

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        n = len(self.numbers)
        mid = n // 2
        if n % 2 == 0:
            return (self.numbers[mid - 1] + self.numbers[mid]) / 2
        return self.numbers[mid]

    def mode(self):
        counts = Counter(self.numbers)
        max_freq = max(counts.values())
        return [k for k, v in counts.items() if v == max_freq]

if __name__ == "__main__":
    data = [1, 2, 2, 3, 4, 4, 4, 5]
    calc = StatisticsCalculator(data)
    print("Mean:", round(calc.mean(), 2))
    print("Median:", round(calc.median(), 2))
    print("Mode:", calc.mode())
