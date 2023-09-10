import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file into a DataFrame
df = pd.read_csv('data1.csv')

# Access the columns
array_sizes = df['ARRAY SIZE']
time_taken = df['TIME TAKEN']

plt.figure(figsize=(8, 6))
# Create a scatter plot
plt.plot(array_sizes, time_taken, marker='o')

# Label the axes
plt.xlabel('ARRAY SIZE')
plt.ylabel('TIME TAKEN ')

# Set a title
plt.title('TASK 1')
    
# Save  the plot
plt.savefig(f'performance_chart1.png')
#display the graph
plt.show()
