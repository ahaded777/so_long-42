#!/bin/bash

# Function to generate an empty map surrounded by walls
generate_empty_map() {
    local rows=$1
    local cols=$2
    local map=""

    # Create the top wall
    for ((i=0; i<cols; i++)); do
        map+="1"
    done
    map+="\n"

    # Create the middle rows with empty spaces
    for ((i=1; i<rows-1; i++)); do
        row="1"  # Start with a wall
        for ((j=1; j<cols-1; j++)); do
            row+="0"  # Add an empty space
        done
        row+="1"  # End with a wall
        map+="$row\n"
    done

    # Create the bottom wall
    for ((i=0; i<cols; i++)); do
        map+="1"
    done

    echo -e "$map"
}

# Function to place P and E in random empty spaces
place_player_and_exit() {
    local -n map_ref=$1
    local rows=$2
    local cols=$3

    # Collect empty positions
    empty_positions=()
    for ((i=1; i<rows-1; i++)); do
        for ((j=1; j<cols-1; j++)); do
            if [[ ${map_ref[i]:j:1} == "0" ]]; then
                empty_positions+=("$i $j")
            fi
        done
    done

    # Check if there are enough empty positions
    if [[ ${#empty_positions[@]} -lt 2 ]]; then
        echo "Error: Not enough empty spaces to place P and E."
        exit 1
    fi

    # Randomly select positions for exit (E) and player (P)
    exit_index=$((RANDOM % ${#empty_positions[@]}))
    exit_position=${empty_positions[$exit_index]}
    exit_row=${exit_position%% *}
    exit_col=${exit_position##* }

    map_ref[exit_row]="${map_ref[exit_row]:0:exit_col}E${map_ref[exit_row]:exit_col+1}"

    # Remove the exit position from the list of empty positions
    unset empty_positions[$exit_index]
    empty_positions=("${empty_positions[@]}")  # Re-index the array

    player_index=$((RANDOM % ${#empty_positions[@]}))
    player_position=${empty_positions[$player_index]}
    player_row=${player_position%% *}
    player_col=${player_position##* }

    map_ref[player_row]="${map_ref[player_row]:0:player_col}P${map_ref[player_row]:player_col+1}"
}

# Function to place a specified number of coins in random empty spaces
place_coins() {
    local -n map_ref=$1
    local rows=$2
    local cols=$3
    local num_coins=$4

    # Collect empty positions
    empty_positions=()
    for ((i=1; i<rows-1; i++)); do
        for ((j=1; j<cols-1; j++)); do
            if [[ ${map_ref[i]:j:1} == "0" ]]; then
                empty_positions+=("$i $j")
            fi
        done
    done

    # Place coins in random positions
    for ((k=0; k<num_coins; k++)); do
        if [[ ${#empty_positions[@]} -eq 0 ]]; then
            echo "No more empty spaces available for coins."
            break
        fi

        coin_index=$((RANDOM % ${#empty_positions[@]}))
        coin_position=${empty_positions[$coin_index]}
        coin_row=${coin_position%% *}
        coin_col=${coin_position##* }

        map_ref[coin_row]="${map_ref[coin_row]:0:coin_col}C${map_ref[coin_row]:coin_col+1}"

        # Remove the coin position from the list of empty positions
        unset empty_positions[$coin_index]
        empty_positions=("${empty_positions[@]}")  # Re-index the array
    done
}

# Function to place random wall segments in empty spaces
place_random_walls() {
    local -n map_ref=$1
    local rows=$2
    local cols=$3
    local num_walls=$4

    # Collect empty positions
    empty_positions=()
    for ((i=1; i<rows-1; i++)); do
        for ((j=1; j<cols-1; j++)); do
            if [[ ${map_ref[i]:j:1} == "0" ]]; then
                empty_positions+=("$i $j")
            fi
        done
    done

    # Place walls in random positions
    for ((k=0; k<num_walls; k++)); do
        if [[ ${#empty_positions[@]} -eq 0 ]]; then
            echo "No more empty spaces available for walls."
            break
        fi

        wall_index=$((RANDOM % ${#empty_positions[@]}))
        wall_position=${empty_positions[$wall_index]}
        wall_row=${wall_position%% *}
        wall_col=${wall_position##* }

        map_ref[wall_row]="${map_ref[wall_row]:0:wall_col}1${map_ref[wall_row]:wall_col+1}"

        # Remove the wall position from the list of empty positions
        unset empty_positions[$wall_index]
        empty_positions=("${empty_positions[@]}")  # Re-index the array
    done
}

# Main script
if [[ $# -ne 4 ]]; then
    echo "Usage: $0 <rows> <columns> <number_of_coins> <number_of_walls>"
    exit 1
fi

rows=$1
cols=$2
num_coins=$3
num_walls=$4

# Validate input
if (( rows < 3 || cols < 3 )); then
    echo "Error: Rows and columns must be at least 3."
    exit 1
fi

# Generate the empty map
map=$(generate_empty_map "$rows" "$cols")

# Convert the map to an array for easier manipulation
map_array=()
while IFS= read -r line; do
    map_array+=("$line")
done <<< "$map"

# Place P and E in random empty spaces
place_player_and_exit map_array "$rows" "$cols"

# Place coins in random empty spaces
place_coins map_array "$rows" "$cols" "$num_coins"

# Place random walls in random empty spaces
place_random_walls map_array "$rows" "$cols" "$num_walls"

# Convert the array back to a string
final_map=""
for line in "${map_array[@]}"; do
    final_map+="$line\n"
done

# Print the final map
echo -e "$final_map"
