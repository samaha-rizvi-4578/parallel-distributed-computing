import matplotlib.pyplot as plt
import pandas as pd

# Load your data from the CSV file
data = pd.read_csv('data.csv')

# Separate data based on SCHEDULING type
static_data = data[data['SCHEDULING'] == 'Static']
dynamic_data = data[data['SCHEDULING'] == 'Dynamic']

# Create a plot for each chunk size (1 and 2)
for chunk_size in [1, 2]:
    plt.figure(figsize=(8, 6))
    
    # Filter data for the current chunk size
    static_chunk_data = static_data[static_data['CHUNK SIZE'] == chunk_size]
    dynamic_chunk_data = dynamic_data[dynamic_data['CHUNK SIZE'] == chunk_size]
    
    # Plot the data
    plt.plot(static_chunk_data['ARRAY SIZE'], static_chunk_data['TIME'], label='Static')
    plt.plot(dynamic_chunk_data['ARRAY SIZE'], dynamic_chunk_data['TIME'], label='Dynamic')
    
    # Customize labels, title, and legend
    plt.xlabel('Array Size')
    plt.ylabel('Time (seconds)')
    plt.title(f'Chunk Size {chunk_size} Performance Comparison')
    plt.legend()
    
    # Save or display the plot
    plt.savefig(f'performance_chunk_{chunk_size}.png')
    plt.show()
