from manim import *

class DoraAndSearch(Scene):
    def construct(self):
        self.camera.background_color = BLACK
        # Title
        title = Text("Dora and Search", font_size=48, color=WHITE).to_edge(UP)
        self.play(Write(title))
        self.wait(1)

        # Problem Description - Centered and as a paragraph
        problem_text = """Find a subsegment [l, r] in a permutation such that:
        - a[l] is NOT the min/max of the subsegment
        - a[r] is NOT the min/max of the subsegment."""
        problem_mobject = Paragraph(problem_text, font_size=30, color=WHITE, line_spacing=1)
        problem_mobject.to_edge(UP).shift(DOWN * 1.5)  # Adjust position as needed
        problem_mobject.move_to(ORIGIN)
        self.play(Write(problem_mobject))
        self.wait(2)
        self.play(FadeOut(problem_mobject))

        algorithm_explanation = [
            "The algorithm iteratively strips elements from the array.",
            "It checks if the leftmost or rightmost element is equal to min or max.",
            "If it is, it increments/decrements the corresponding pointer and value.",
            "If neither end is min/max, a valid subsegment is found."
        ]
        algo_mobjects = [Text(line, font_size=30) for line in algorithm_explanation]
        algorithm_group = VGroup(*algo_mobjects).arrange(DOWN).move_to(ORIGIN)
        self.play(Write(algorithm_group))
        self.wait(1)
        self.play(FadeOut(algorithm_group))

        # Test Case
        array = [1, 2, 4, 7, 6, 9, 8, 5, 3]
        n = len(array)

        array_text = Text(f"Array: {array}", font_size=36).to_edge(UP).shift(DOWN*2)
        self.play(Write(array_text))
        self.wait(1)

        # Box setup
        boxes = VGroup()
        box_groups = []
        for i, num in enumerate(array):
            box = Square(side_length=0.7, color=WHITE, stroke_width=2, fill_color=BLACK, fill_opacity=1)
            text = Text(str(num), color=WHITE, font_size=24)
            text.move_to(box.get_center())
            box_group = VGroup(box, text)
            box_group.move_to(RIGHT * (i * 0.8 - 3.5))  # small gaps
            boxes.add(box_group)
            box_groups.append(box_group)
        self.play(*[FadeIn(box) for box in box_groups])

        # Initial yellow range selection
        selector = SurroundingRectangle(boxes, color=YELLOW, buff=0.1, stroke_width=4)
        self.play(Create(selector))

        # Show min and max
        min_val = 1
        max_val = n
        min_text = Text(f"min: {min_val}", font_size=30).to_edge(DOWN).shift(LEFT*3)
        max_text = Text(f"max: {max_val}", font_size=30).to_edge(DOWN).shift(RIGHT*3)
        self.play(Write(min_text), Write(max_text))

        l, r = 0, n - 1

        # Animation loop for stripping
        while l <= r:
            self.wait(0.8)
            # Update min and max display
            min_text_new = Text(f"min: {min_val}", font_size=30).to_edge(DOWN).shift(LEFT*3)
            max_text_new = Text(f"max: {max_val}", font_size=30).to_edge(DOWN).shift(RIGHT*3)
            self.play(Transform(min_text, min_text_new), Transform(max_text, max_text_new))

            if array[l] == min_val:
                # Animate min blink green
                self.play(min_text.animate.set_color(GREEN), run_time=0.3)
                self.play(min_text.animate.set_color(WHITE), run_time=0.3)

                # Animate left pointer increment
                self.play(boxes[l].animate.set_color(RED), run_time=0.5)
                l += 1
                min_val += 1
            elif array[l] == max_val:
                # Animate max blink green
                self.play(max_text.animate.set_color(GREEN), run_time=0.3)
                self.play(max_text.animate.set_color(WHITE), run_time=0.3)

                self.play(boxes[l].animate.set_color(RED), run_time=0.5)
                l += 1
                max_val -= 1
            elif array[r] == min_val:
                # Animate min blink green
                self.play(min_text.animate.set_color(GREEN), run_time=0.3)
                self.play(min_text.animate.set_color(WHITE), run_time=0.3)

                self.play(boxes[r].animate.set_color(RED), run_time=0.5)
                r -= 1
                min_val += 1
            elif array[r] == max_val:
                # Animate max blink green
                self.play(max_text.animate.set_color(GREEN), run_time=0.3)
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

        # Result Display
        if l > r:
            # No valid segment
            result = Text("-1", color=RED, font_size=48).next_to(selector, DOWN)
            self.play(Write(result))
        else:
            # Valid segment found
            l_val = l + 1
            r_val = r + 1
            result = Text(f"Index Range: {l_val} to {r_val}", color=GREEN, font_size=48).next_to(selector, DOWN)
            self.play(Write(result))

        self.wait(2)
