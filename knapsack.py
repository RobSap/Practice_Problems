def main(value, calories):
    print_arrays(value,calories)
    value, calories = sort_by_value(value,calories)
    print("")
    print_arrays(value,calories)


def sort_by_value(value, calories):
    #Using Bubble up sort
    n = len(value)
    swap = True
    while(swap):
        swap = False
        for i in range(1,n):
            if value[i-1] > value[i]:
                swap = True
                temp = value[i]
                temp2 = calories[i]
                value[i]= value[i-1]
                calories[i]=calories[i-1]
                calories[i-1]=temp2
                value[i-1]=temp

    return value, calories

def sort_by_calories(value, calories):
    return value, valories
 

def greedy(value, calories):
    return    

def print_arrays(value,calories):
    for i in range(len(value)):
        print("Value: " + str(value[i]) + " Calroies: " + str(calories[i]))
    return

if __name__=="__main__":
   
    food_value = [89,90,30,50,90,79,90,10]
    food_calories = [123,154,258,354,365,150,95,195]
    
    #For both of these you can not repeat the menu
    #Find the most value for the lowest calories
    #Find the most calories for the lowest value
    
    main(food_value, food_calories)

 
