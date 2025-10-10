from manim import *

# filepath: /home/darelife/Desktop/prog/competitiveProgramming/manim/C_Triple_Removal.py

# Portrait orientation settings
config.pixel_width = 1080
config.pixel_height = 1920
config.frame_width = 9
config.frame_height = 16

class TripleRemovalProblem(Scene):
    def construct(self):
        self.camera.background_color = BLACK

        # Title
        title = Text("Triple Removal Problem", font_size=42).to_edge(UP).shift(DOWN * 0.5)
        subtitle = Text("Array of 0s and 1s", font_size=32, color=YELLOW)
        subtitle.next_to(title, DOWN, buff=0.3)
        self.play(Write(title), Write(subtitle))
        self.wait(1)

        # Problem Description in smaller chunks with better formatting
        lines = [
            "Given an array b of 0s and 1s,",
            "perform triple removal operations:",
            "Remove three identical elements i<j<k,",
            "cost = min(k-j, j-i).",
            "Find min total cost to empty the array",
            "for subarrays [l..r] (queries given).",
            "If impossible, cost = -1."
        ]
        
        text_lines = VGroup(*[
            Text(line, font_size=26, color=WHITE) for line in lines
        ]).arrange(DOWN, center=True, aligned_edge=ORIGIN).move_to(ORIGIN).shift(UP * 1)
        
        image = ImageMobject("./algo.png")  # Replace with actual image path
        image.height = 3  # Adjust size as needed
        image.next_to(text_lines, DOWN, buff=2)  # Position below text

        self.play(Write(text_lines), FadeIn(image))
        self.wait(10)
        self.play(FadeOut(text_lines), FadeOut(image))

        # Example Array first
        array = [1, 0, 1, 1, 0, 0]  # Random example array
        n = len(array)
        array_text = Text("Example Array:", font_size=32).to_edge(UP).shift(DOWN*3)
        self.play(Write(array_text))
        self.wait(0.5)

        # Draw array as boxes
        boxes = VGroup()
        box_groups = []
        box_size = 0.7
        for i, num in enumerate(array):
            box = Square(side_length=box_size, color=WHITE, stroke_width=2, fill_color=BLACK, fill_opacity=1)
            text = Text(str(num), color=WHITE, font_size=24)
            text.move_to(box.get_center())
            box_group = VGroup(box, text)
            x_offset = (i - (n-1)/2) * (box_size * 1.2)
            box_group.move_to(RIGHT * x_offset)
            boxes.add(box_group)
            box_groups.append(box_group)
        
        array_group = VGroup(*box_groups).move_to(ORIGIN)
        self.play(*[FadeIn(box) for box in box_groups])
        self.wait(2)
        # Highlight counts
        count_0 = sum(1 for x in array if x == 0)
        count_1 = sum(1 for x in array if x == 1)
        count_text = Text(f"0s: {count_0}, 1s: {count_1}", font_size=28, color=BLUE).move_to(DOWN * 3)
        self.play(Write(count_text))
        self.wait(2)

        # Mark indices 0, 2, 3 with green background and black text
        self.play(
            *[box_groups[i][0].animate.set_fill(GREEN) for i in [0, 2, 3]],
            *[box_groups[i][1].animate.set_color(BLACK) for i in [0, 2, 3]]
        )
        self.wait(2)

        # Mark indices 1, 4, 5 with blue background and white text
        self.play(
            *[box_groups[i][0].animate.set_fill(BLUE) for i in [1, 4, 5]],
            *[box_groups[i][1].animate.set_color(WHITE) for i in [1, 4, 5]]
        )
        answer_text = Text("Answer: 2", font_size=32, color=GREEN).move_to(DOWN * 5)
        self.play(Write(answer_text))
        self.wait(2)
        self.play(FadeOut(answer_text))
        self.play(FadeOut(count_text), FadeOut(array_text), FadeOut(array_group))

        # Hints with line breaks and only 3 hints
        hints = [
            "Hint 1: Consider the number\nof 0s and 1s, along with the divisibility by 3,",
            "Hint 2: Use prefix sums since we don't edit the array,\nonly query subarrays for counts.",
            "Hint 3: What if the array is of a special type\nlike 010101 or 101010"
        ]
        hint_mobjects = [Text(hint, font_size=24) for hint in hints]
        hint_group = VGroup(*hint_mobjects).arrange(DOWN, aligned_edge=LEFT, buff=0.3).move_to(ORIGIN)
        
        # Show first hint
        self.play(Write(hint_mobjects[0]))
        self.wait(2)
        
        # Pause between hints
        pause_text = Text("Pause now.", font_size=32, color=RED).move_to(DOWN * 4)
        self.play(Write(pause_text))
        self.wait(2)
        self.play(FadeOut(pause_text))
        
        # Show second hint
        self.play(Write(hint_mobjects[1]))
        self.wait(2)
        
        # Another pause
        self.play(Write(pause_text))
        self.wait(2)
        self.play(FadeOut(pause_text))
        
        # Show third hint
        self.play(Write(hint_mobjects[2]))
        self.wait(2)
        
        self.play(FadeOut(hint_group))