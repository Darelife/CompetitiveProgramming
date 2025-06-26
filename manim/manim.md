# How to Run Manim Files

Manim (Mathematical Animation Engine) is a Python library for creating mathematical animations. Here's a comprehensive guide on how to run manim files.

## Installation

First, make sure you have manim installed:

```bash
# Install manim community edition (recommended)
pip install manim

# Or install manim with additional dependencies
pip install "manim[gui,jupyterlab]"
```

## Basic Usage

### 1. Running a Scene

The basic command structure is:
```bash
manim [OPTIONS] FILE_NAME SCENE_NAME
```

Examples:
```bash
# Render a specific scene
manim A_1d_eraser.py MyScene

# Render with preview (opens video after rendering)
manim -p A_1d_eraser.py MyScene

# Render in low quality for faster preview
manim -pql A_1d_eraser.py MyScene

# Render in high quality
manim -pqh A_1d_eraser.py MyScene
```

### 2. Quality Options

- `-ql` or `--quality=low`: 480p15 (fast rendering)
- `-qm` or `--quality=medium`: 720p30 (default)
- `-qh` or `--quality=high`: 1080p60 (slow but high quality)
- `-qk` or `--quality=fourk`: 2160p60 (4K quality)

### 3. Useful Options

- `-p` or `--preview`: Preview the video after rendering
- `-f` or `--format`: Output format (mp4, gif, png, etc.)
- `-s` or `--save_last_frame`: Save the last frame as an image
- `-a` or `--write_all`: Render all scenes in the file
- `-o OUTPUT_FILE` or `--output_file OUTPUT_FILE`: Specify output filename

## Examples for Your Files

Based on your Python files, here are specific commands:

```bash
# Preview A_1d_eraser.py in low quality
manim -pql A_1d_eraser.py

# Render C_Dora_and_Search.py in high quality
manim -qh C_Dora_and_Search.py

# Save last frame of C_Trinity.py as image
manim -s C_Trinity.py

# Render all scenes in D_Reachability_and_tree.py
manim -a D_Reachability_and_tree.py
```

## Finding Scene Names

If you're not sure about the scene names in a file, you can:

1. **List all scenes in a file:**
   ```bash
   manim --list_scenes A_1d_eraser.py
   ```

2. **Check the Python file directly** - look for classes that inherit from `Scene`:
   ```python
   class MyScene(Scene):  # This is a scene name
       def construct(self):
           # Scene code here
   ```

## Troubleshooting

### Common Issues:

1. **No scene found**: Make sure your class inherits from `Scene` and the scene name is correct
2. **Module not found**: Ensure manim is installed in the correct Python environment
3. **LaTeX errors**: Install a LaTeX distribution if using mathematical text
4. **Permission errors**: Check write permissions in the output directory

### Debug Mode:
```bash
# Run with verbose output for debugging
manim -v DEBUG A_1d_eraser.py MyScene
```

## Output Location

By default, manim saves rendered videos to:
- `./media/videos/[filename]/[quality]/[scene_name].mp4`
- Images to: `./media/images/[filename]/[scene_name].png`

## Interactive Development

For faster development, you can use:
```bash
# Watch mode - re-renders when file changes
manim --watch A_1d_eraser.py MyScene
```

## Jupyter Notebook Integration

If using Jupyter notebooks:
```python
%%manim -pql MyScene

class MyScene(Scene):
    def construct(self):
        # Your scene code here
```

## Quick Reference Card

| Command | Description |
|---------|-------------|
| `manim -pql file.py Scene` | Preview low quality |
| `manim -pqh file.py Scene` | Preview high quality |
| `manim -s file.py Scene` | Save last frame |
| `manim -a file.py` | Render all scenes |
| `manim --list_scenes file.py` | List all scenes |
| `manim -f gif file.py Scene` | Output as GIF |

---

*Remember: Replace `Scene` with the actual name of your scene class in the Python file.*