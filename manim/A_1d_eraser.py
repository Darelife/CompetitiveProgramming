from manim import *

config.pixel_width = 1080
config.pixel_height = 1920
config.frame_width = 9
config.frame_height = 16

class Eraser1D(Scene):
    def construct(self):
        # Testcase
        n = 8
        k = 3
        s = 'WBWBWBBB'
        cell_size = 0.75  # Reduced cell size
        gap = 0.05  # Small gap between cells
        stroke_color = GRAY  # All outlines gray
        
        # Create title
        title = Text("1D Eraser Problem", font_size=36).to_edge(UP).shift(DOWN * 0.5)
        self.play(Write(title))
        
        # Add problem description
        # problem_description = Text(
        #     "Given a strip of paper\nwith black and white cells,\nfind the minimum operations \nto turn all black cells to white.\nIn one operation, you can turn \nk consecutive cells to white.",
        #     font_size=32,
        #     line_spacing=1.5  # Adjust this value to increase/decrease space
        # ).move_to(ORIGIN).shift(UP * 1.5)

        # self.play(Write(problem_description))
        # self.wait(4)
        # self.play(FadeOut(problem_description))

        lines = [
            "Given a strip of paper",
            "with black and white cells,",
            "find the minimum operations",
            "to turn all black cells to white.",
            "In one operation, you can turn",
            "k consecutive cells to white."
        ]

        # Create Text mobjects
        text_lines = VGroup(*[
            Text(line, font_size=32) for line in lines
        ]).arrange(DOWN, center=True, aligned_edge=ORIGIN).move_to(ORIGIN).shift(UP * 1.5)

        image = ImageMobject("./algo.png")  # Replace with actual image path
        image.height = 3  # Adjust size as needed
        image.next_to(text_lines, DOWN, buff=2)  # Position below text

        # Add to scene
        self.play(Write(text_lines), FadeIn(image))
        self.wait(4)
        self.play(FadeOut(text_lines), FadeOut(image))


        # Create cell boxes
        boxes = VGroup()
        for i, c in enumerate(s):
            fill_color = WHITE if c == 'W' else BLACK
            box = Square(cell_size, color=stroke_color, stroke_width=2).set_fill(fill_color, 1)
            num_color = BLACK if c == 'W' else WHITE
            num = Text(str(i), color=num_color, font_size=30)
            num.move_to(box.get_center())  # Center number inside box
            cell = VGroup(box, num).move_to(RIGHT * (i - n/2 + 0.5) * (cell_size + gap))
            boxes.add(cell)

        # Add to scene
        self.play(LaggedStartMap(FadeIn, boxes, shift=UP, lag_ratio=0.1))
        self.wait(0.5)
        
        # Add problem statement
        problem = Text("We can erase k consecutive cells at once", font_size=24, color=YELLOW).next_to(boxes, UP, buff=0.5)
        self.play(Write(problem))
        self.wait(0.5)

        # Outline rectangle (operation range) - fix position to be centered on first box
        outline = Rectangle(
            width=cell_size * k + gap * (k - 1),
            height=cell_size * 1.01,  # Increased height
            color=YELLOW,
            stroke_width=4
        )
        
        # Calculate the center position for the outline based on the first k boxes
        start_box_center = boxes[0].get_center()
        end_box_center = boxes[min(k-1, n-1)].get_center()
        outline_center = (start_box_center + end_box_center) / 2
        outline.move_to(outline_center)
        
        self.play(Create(outline), run_time=1)
        self.wait(0.5)
        i = 0
        ans = 0
        counter = Text("Operations: 0", font_size=36).move_to(ORIGIN + DOWN * 3)
        self.play(Write(counter))
        
        # Add rule explanation
        rule = Text("Rule: Only erase when encountering a BLACK cell", 
               font_size=24, color=RED).move_to(ORIGIN + DOWN * 2)
        self.play(Write(rule))
        self.wait(0.5)
        
        while i < n:
            # Move outline to current position to show which cell we're examining
            current_box_center = boxes[i].get_center()
            end_idx = min(i + k - 1, n - 1)
            end_box_center = boxes[end_idx].get_center()
            target_center = (current_box_center + end_box_center) / 2
            
            self.play(outline.animate.move_to(target_center), run_time=0.5)
            
            if s[i] == 'B':
                # Add text to show we found a black cell
                action_text = Text("Found BLACK cell! Erasing...", font_size=28, color=YELLOW).move_to(ORIGIN + DOWN * 1)
                self.play(Write(action_text))
                
                # Increment answer counter
                ans += 1
                new_counter = Text(f"Operations: {ans}", font_size=36).move_to(ORIGIN + DOWN * 3)
                
                # Turn all k cells in this range to white with gray outline
                cells_to_update = []
                for j in range(i, min(i + k, n)):
                    box, num = boxes[j]
                    cells_to_update.append(
                    AnimationGroup(
                        box.animate.set_fill(WHITE, 1),
                        num.animate.set_color(BLACK)
                    )
                    )
                    # Update the string s to reflect the change
                    s = s[:j] + 'W' + s[j+1:]
                
                self.play(
                    LaggedStart(*cells_to_update, lag_ratio=0.2),
                    Transform(counter, new_counter),
                    Flash(outline, color=YELLOW, line_length=0.1, num_lines=20)
                )
                
                self.play(FadeOut(action_text))
                
                # Skip to next position after erasing k cells
                # Only show skip message if we're not at the end
                if i + k < n:
                    skip_text = Text(f"Skip k cells forward...", font_size=28, color=GREEN).move_to(ORIGIN + DOWN * 1)
                    self.play(Write(skip_text))
                    self.wait(1)
                    self.play(FadeOut(skip_text))
                i += k
            
            else:
                # Add text to show we found a white cell
                action_text = Text("Found WHITE cell, moving to next...", font_size=28, color=BLUE).move_to(ORIGIN + DOWN * 1)
                self.play(Write(action_text))
                self.wait(0.3)
                self.play(FadeOut(action_text))
                
                # Move to next position
                i += 1
            
        # Final result
        self.play(FadeOut(rule))
        result_text = Text(f"Total operations needed: {ans}", font_size=36, color=GREEN).move_to(ORIGIN + DOWN * 1.5)
        self.play(Write(result_text))
        self.wait(5)
