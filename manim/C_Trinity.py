from manim import *

class TrinityProblem(Scene):
    def construct(self):
        self.camera.background_color = BLACK

        # Title
        title = Text("C. Trinity - Triangle Array Problem", font_size=48, color=WHITE).to_edge(UP)
        self.play(Write(title))
        self.wait(1)

        # Problem Description
        problem_text = """Given an array a of n elements, you can set any a[i] := a[j]
    any number of times.

    Find the minimum number of operations to make every triplet
    (x, y, z) form a non-degenerate triangle:
    a[x] + a[y] > a[z]
    a[y] + a[z] > a[x]
    a[z] + a[x] > a[y]."""
        problem_mobject = Paragraph(problem_text, font_size=28, color=WHITE, line_spacing=1.2)
        problem_mobject.to_edge(UP).shift(DOWN * 1.5)
        problem_mobject.move_to(ORIGIN)
        self.play(Write(problem_mobject))
        self.wait(2)
        self.play(FadeOut(problem_mobject))

        # Algorithm Explanation
        explanation = [
            "1. Sort the array.",
            "2. Use a sliding window to find the largest segment",
            "   where every triplet forms a triangle.",
            "3. Check if the two smallest numbers sum to more",
            "   than the largest number in each window.",
            "4. The answer is n - (window size)."
        ]
        explanation_mobjects = [Text(line, font_size=28) for line in explanation]
        explanation_group = VGroup(*explanation_mobjects).arrange(DOWN, aligned_edge=LEFT).move_to(ORIGIN)
        self.play(Write(explanation_group))
        self.wait(2)
        self.play(FadeOut(explanation_group))
        # Example Array
        array = [1, 2, 3, 4, 5, 6, 7]
        n = len(array)
        array_text = Text(f"Array: {array}", font_size=36).to_edge(UP).shift(DOWN*2)
        self.play(Write(array_text))
        self.wait(1)

        # Draw array as boxes
        boxes = VGroup()
        box_groups = []
        for i, num in enumerate(array):
            box = Square(side_length=0.7, color=WHITE, stroke_width=2, fill_color=BLACK, fill_opacity=1)
            text = Text(str(num), color=WHITE, font_size=24)
            text.move_to(box.get_center())
            box_group = VGroup(box, text)
            box_group.move_to(RIGHT * (i * 0.8 - 2.4))
            boxes.add(box_group)
            box_groups.append(box_group)
        self.play(*[FadeIn(box) for box in box_groups])

        # Sliding window visualization
        l, ans = 0, n - 2
        selector = SurroundingRectangle(VGroup(*boxes[0:3]), color=YELLOW, buff=0.1, stroke_width=4)
        self.play(Create(selector))
        self.wait(0.5)

        # Step-by-step window movement
        min_ops = n - 2
        best_l, best_r = 0, 2
        for r in range(2, n):
            while r - l >= 2 and array[l] + array[l+1] <= array[r]:
                # Highlight invalid window
                invalid_selector = SurroundingRectangle(VGroup(*boxes[l:r+1]), color=RED, buff=0.1, stroke_width=4)
                self.play(Transform(selector, invalid_selector), run_time=0.5)
                # Show why invalid
                sum_text = Text(f"{array[l]} + {array[l+1]} <= {array[r]}", font_size=28, color=RED)
                sum_text.next_to(selector, DOWN)
                self.play(Write(sum_text))
                self.wait(0.7)
                self.play(FadeOut(sum_text))
                l += 1
            # Highlight valid window
            valid_selector = SurroundingRectangle(VGroup(*boxes[l:r+1]), color=YELLOW, buff=0.1, stroke_width=4)
            self.play(Transform(selector, valid_selector), run_time=0.5)
            # Show why valid
            sum_text = Text(f"{array[l]} + {array[l+1]} > {array[r]}", font_size=28, color=GREEN)
            sum_text.next_to(selector, DOWN)
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
        result_text = Text(
            f"Minimum operations: {min_ops}\nChange {n - (best_r - best_l + 1)} elements",
            font_size=36, color=GREEN
        ).next_to(selector, DOWN, buff=1)
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