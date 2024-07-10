from pydub import AudioSegment
from scipy.io import wavfile
import sys

def convert_to_snes_quality(input_file, output_file):
    # Load the audio file
    audio = AudioSegment.from_file(input_file)
    
    # Convert to mono
    audio = audio.set_channels(1)
    
    # Resample to 32000 Hz
    audio = audio.set_frame_rate(32000)
    
    # Convert to 16-bit samples
    audio = audio.set_sample_width(2)  # 2 bytes = 16 bits
    
    # Export as a WAV file with the desired SNES-like quality
    audio.export(output_file, format="wav")
    
    print(f"Converted '{input_file}' to SNES-like quality as '{output_file}'")


# Example use
input_file_path = sys.argv[1]
output_file_path = sys.argv[2]
convert_to_snes_quality(input_file_path, output_file_path)