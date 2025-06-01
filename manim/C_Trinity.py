from manim import *

# Portrait orientation settings
config.pixel_width = 1080
config.pixel_height = 1920
config.frame_width = 9
config.frame_height = 16

class TrinityProblem(Scene):
    def construct(self):
        self.camera.background_color = BLACK

        # Title
        title = Text("C. Trinity", font_size=42).to_edge(UP).shift(DOWN * 0.5)
        subtitle = Text("Triangle Array Problem", font_size=32, color=YELLOW)
        subtitle.next_to(title, DOWN, buff=0.3)
        self.play(Write(title), Write(subtitle))
        self.wait(1)

        # Problem Description in smaller chunks
        lines = [
            "Given an array of n elements,",
            "you can set any a[i] := a[j]",
            "any number of times.\n",
            "Find the minimum operations to make",
            "every triplet form a triangle:",
            "a[x] + a[y] > a[z]",
            "a[y] + a[z] > a[x]",
            "a[z] + a[x] > a[y]"
        ]
        
        text_lines = VGroup(*[
            Text(line, font_size=28) for line in lines
        ]).arrange(DOWN, center=True, aligned_edge=ORIGIN).move_to(ORIGIN).shift(UP * 1)
        
        image = ImageMobject("./algo.png")  # Replace with actual image path
        image.height = 3  # Adjust size as needed
        image.next_to(text_lines, DOWN, buff=2)  # Position below text

        self.play(Write(text_lines), FadeIn(image))
        self.wait(10)
        self.play(FadeOut(text_lines), FadeOut(image))

        # Algorithm Explanation - more compact
        explanation = [
            "1. Sort the array",
            "2. Find largest segment where",
            "   every triplet forms a triangle",
            "3. Check if smallest two numbers >",
            "   largest number in each window",
            "4. Answer: n - (window size)"
        ]
        explanation_mobjects = [Text(line, font_size=26) for line in explanation]
        explanation_group = VGroup(*explanation_mobjects).arrange(DOWN, aligned_edge=LEFT, buff=0.3).move_to(ORIGIN)
        self.play(Write(explanation_group))
        self.wait(2)
        self.play(FadeOut(explanation_group))

        # Example Array
        array = [1, 2, 3, 4, 5, 6, 7]
        n = len(array)
        array_text = Text("Example Array:", font_size=32).to_edge(UP).shift(DOWN*3)
        self.play(Write(array_text))
        self.wait(0.5)

        # Draw array as boxes - horizontally arranged in a single line
        boxes = VGroup()
        box_groups = []
        box_size = 0.7
        for i, num in enumerate(array):
            box = Square(side_length=box_size, color=WHITE, stroke_width=2, fill_color=BLACK, fill_opacity=1)
            text = Text(str(num), color=WHITE, font_size=24)
            text.move_to(box.get_center())
            box_group = VGroup(box, text)
            # Position in a single line
            x_offset = (i - (n-1)/2) * (box_size * 1.2)  # Evenly space with gap between boxes
            box_group.move_to(RIGHT * x_offset)
            boxes.add(box_group)
            box_groups.append(box_group)
        
        array_group = VGroup(*box_groups).move_to(ORIGIN)
        self.play(*[FadeIn(box) for box in box_groups])

        # Sliding window visualization - adjust for portrait
        l, ans = 0, n - 2
        # Calculate buffer based on box size
        box_buffer = box_size * 0.15  # 15% of box size for buffer
        selector = SurroundingRectangle(VGroup(*boxes[0:3]), color=YELLOW, buff=box_buffer, stroke_width=4)
        self.play(Create(selector))
        self.wait(0.5)
        # Step-by-step window movement
        min_ops = n - 2
        best_l, best_r = 0, 2
        
        # Position for the validation text
        validation_pos = DOWN * 3.5
        
        for r in range(2, n):
            while r - l >= 2 and array[l] + array[l+1] <= array[r]:
                # Highlight invalid window
                invalid_selector = SurroundingRectangle(VGroup(*boxes[l:r+1]), color=RED, buff=0.1, stroke_width=4)
                self.play(Transform(selector, invalid_selector), run_time=0.5)
                # Show why invalid
                sum_text = Text(f"{array[l]} + {array[l+1]} ≤ {array[r]}", font_size=28, color=RED)
                sum_text.move_to(validation_pos)
                self.play(Write(sum_text))
                self.wait(0.7)
                self.play(FadeOut(sum_text))
                l += 1
            
            # Highlight valid window
            valid_selector = SurroundingRectangle(VGroup(*boxes[l:r+1]), color=YELLOW, buff=0.1, stroke_width=4)
            self.play(Transform(selector, valid_selector), run_time=0.5)
            # Show why valid
            sum_text = Text(f"{array[l]} + {array[l+1]} > {array[r]}", font_size=28, color=GREEN)
            sum_text.move_to(validation_pos)
            self.play(Write(sum_text))
            self.wait(0.7)
            self.play(FadeOut(sum_text))
            
            # Update answer
            window_size = r - l + 1
            ops_needed = n - window_size
            if ops_needed < min_ops:
                min_ops = ops_needed
                best_l, best_r = l, r

        self.wait(1)

        # Final highlight of best window
        final_selector = SurroundingRectangle(VGroup(*boxes[best_l:best_r+1]), color=GREEN, buff=0.1, stroke_width=6)
        self.play(Transform(selector, final_selector))
        self.wait(0.5)
        # Show largest size that satisfies triangle inequality
        largest_size = best_r - best_l + 1
        size_text = Text(
            f"Largest size that satisfies: {largest_size}",
            font_size=28, color=BLUE
        ).move_to(DOWN * 3)  # Changed from DOWN * 4
        
        equation_text = Text(
            f"Min operations = n - largest size = {n} - {largest_size} = {min_ops}",
            font_size=28, color=YELLOW
        ).next_to(size_text, DOWN, buff=0.3)
        
        self.play(Write(size_text))
        self.wait(0.5)
        self.play(Write(equation_text))
        self.wait(1.5)
        
        # Result text - positioned lower to fit portrait mode
        result_text = Text(
            f"Minimum operations: {min_ops}",
            font_size=32, color=GREEN
        ).next_to(equation_text, DOWN, buff=0.4)
        
        self.play(Write(result_text))
        self.wait(2)

        # Optional: Show which elements to change
        if min_ops > 0:
            to_change = [i for i in range(n) if i < best_l or i > best_r]
            for idx in to_change:
                highlight = SurroundingRectangle(boxes[idx], color=RED, buff=0.05, stroke_width=4)
                self.play(Create(highlight), run_time=0.3)
                self.wait(0.2)
                self.play(FadeOut(highlight), run_time=0.2)
        self.wait(1)
