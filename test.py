class lol:
    def __init__(self, num):
        self.num = num
        
    def __repr__(self):
        return f"lol is{self.num}"
    
class printer:
    def __init__(self):
        return
    
    def show(self):
        print(f"{lol(12)}")
        
test = printer()
test.show()