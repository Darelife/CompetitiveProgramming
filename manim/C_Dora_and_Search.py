from manim import *

# Portrait orientation settings
config.pixel_width = 1080
config.pixel_height = 1920
config.frame_width = 9
config.frame_height = 16

class DoraAndSearch(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        # Title
        title = Text("Dora and Search", font_size=42).to_edge(UP).shift(DOWN * 0.5)
        self.play(Write(title))
        self.wait(1)

        # Problem Description - Formatted for portrait
        lines = [
            "Find a subsegment [l, r] in a permutation",
            "such that:",
            "- a[l] is NOT the min/max of the subsegment",
            "- a[r] is NOT the min/max of the subsegment"
        ]

        text_lines = VGroup(*[
            Text(line, font_size=28) for line in lines
        ]).arrange(DOWN, center=True, aligned_edge=ORIGIN).move_to(ORIGIN).shift(UP * 2)

        # Add an image
        image = ImageMobject("./algo.png")  # Replace with actual image path
        image.height = 3  # Adjust size as needed
        image.next_to(text_lines, DOWN, buff=2)  # Position below text

        self.play(Write(text_lines), FadeIn(image))
        self.wait(3)
        self.play(FadeOut(text_lines), FadeOut(image))

        # Algorithm explanation - Adjusted for portrait
        algorithm_explanation = [
            "1. Iteratively strip elements from the array",
            "2. Check if leftmost/rightmost element",
            "   equals min or max",
            "3. If it is, increment/decrement the",
            "   corresponding pointer and min/max value",
            "4. If neither end is min/max, a valid",
            "   subsegment is found"
        ]
        algo_mobjects = [Text(line, font_size=26) for line in algorithm_explanation]
        algorithm_group = VGroup(*algo_mobjects).arrange(DOWN, aligned_edge=LEFT, buff=0.3).move_to(ORIGIN)
        self.play(Write(algorithm_group))
        self.wait(3)
        self.play(FadeOut(algorithm_group))

        # Test Case
        array = [1, 9, 7, 4, 6, 8, 5, 3, 2]
        n = len(array)

        array_text = Text("Example Array:", font_size=32).to_edge(UP).shift(DOWN*5)
        self.play(Write(array_text))
        self.wait(0.5)

        # Box setup - Adjusted for narrower portrait display
        boxes = VGroup()
        box_groups = []
        box_size = 0.7
        for i, num in enumerate(array):
            box = Square(side_length=box_size, color=WHITE, stroke_width=2, fill_color=BLACK, fill_opacity=1)
            text = Text(str(num), color=WHITE, font_size=24)
            text.move_to(box.get_center())
            box_group = VGroup(box, text)
            # Position horizontally with smaller gaps for portrait
            x_offset = (i - (n-1)/2) * (box_size * 1.1)  # Reduced spacing
            box_group.move_to(RIGHT * x_offset)
            boxes.add(box_group)
            box_groups.append(box_group)
        
        array_group = VGroup(*box_groups).move_to(ORIGIN)
        self.play(*[FadeIn(box) for box in box_groups])

        # Initial yellow range selection
        selector = SurroundingRectangle(boxes, color=YELLOW, buff=0.1, stroke_width=4)
        self.play(Create(selector))

        # Show min and max - Repositioned for portrait
        min_val = 1
        max_val = n
        min_text = Text(f"min: {min_val}", font_size=30).move_to(DOWN * 2 + LEFT * 2)
        max_text = Text(f"max: {max_val}", font_size=30).move_to(DOWN * 2 + RIGHT * 2)
        self.play(Write(min_text), Write(max_text))

        l, r = 0, n - 1

        # Animation loop for stripping
        while l <= r:
            self.wait(0.8)
            # Update min and max display
            min_text_new = Text(f"min: {min_val}", font_size=30).move_to(DOWN * 2 + LEFT * 2)
            max_text_new = Text(f"max: {max_val}", font_size=30).move_to(DOWN * 2 + RIGHT * 2)
            self.play(Transform(min_text, min_text_new), Transform(max_text, max_text_new))

            if array[l] == min_val:
                # Animate min blink green
                self.play(min_text.animate.set_color(GREEN), run_time=0.6)
                self.play(min_text.animate.set_color(WHITE), run_time=0.3)

                # Animate left pointer increment
                self.play(boxes[l].animate.set_color(RED), run_time=0.5)
                l += 1
                min_val += 1
            elif array[l] == max_val:
                # Animate max blink green
                self.play(max_text.animate.set_color(GREEN), run_time=0.6)
                self.play(max_text.animate.set_color(WHITE), run_time=0.3)

                self.play(boxes[l].animate.set_color(RED), run_time=0.5)
                l += 1
                max_val -= 1
            elif array[r] == min_val:
                # Animate min blink green
                self.play(min_text.animate.set_color(GREEN), run_time=0.6)
                self.play(min_text.animate.set_color(WHITE), run_time=0.3)

                self.play(boxes[r].animate.set_color(RED), run_time=0.5)
                r -= 1
                min_val += 1
            elif array[r] == max_val:
                # Animate max blink green
                self.play(max_text.animate.set_color(GREEN), run_time=0.6)
                self.play(max_text.animate.set_color(WHITE), run_time=0.3)

                self.play(boxes[r].animate.set_color(RED), run_time=0.5)
                r -= 1
                max_val -= 1
            else:
                break

            # Update yellow selector to new [l, r]
            if l <= r:
                new_selector = SurroundingRectangle(VGroup(*boxes[l:r+1]), color=YELLOW, buff=0.1, stroke_width=4)
                self.play(Transform(selector, new_selector))
            else:
                # No valid segment
                break

        self.wait(1)

        # Result Display - Repositioned for portrait
        if l > r:
            # No valid segment
            result = Text("-1", color=RED, font_size=48).move_to(DOWN * 4)
            self.play(Write(result))
        else:
            # Valid segment found
            l_val = l + 1
            r_val = r + 1
            result = Text(f"Index Range: {l_val} to {r_val}", color=GREEN, font_size=36).move_to(DOWN * 4)
            self.play(Write(result))

        self.wait(2)
