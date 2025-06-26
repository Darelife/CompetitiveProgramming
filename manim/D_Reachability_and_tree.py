"""
This script provides a detailed visual explanation for the competitive programming
problem "D. Reachability and Tree". The goal is to direct the edges of a given
tree with N nodes to create exactly N reachable pairs (a, b).

The explanation follows this structure:
1.  Introduction: State the problem clearly.
2.  Simple Case (Path Graph):
    - Show that a simple alternating direction strategy yields N-1 pairs.
    - Introduce the core idea: creating a single directed path of length 2
      (e.g., u -> v -> w) generates an extra pair (u, w).
    - Demonstrate how modifying the alternating pattern to include one such
      path results in exactly N pairs for a path graph.
3.  Generalization to a Tree:
    - Pose the question: Can this logic be applied to any three connected
      nodes in a tree?
    - Show a counter-example where the central node has a degree greater
      than 2. Applying the u -> v -> w logic here can create too many
      additional paths, resulting in more than N pairs.
    - Present the key condition: The strategy works if the central node 'v'
      has a degree of exactly 2. This isolates the new path and prevents
      unwanted interactions.
4.  Complex Example:
    - Apply the algorithm to a tree where the degree-2 node's neighbors are
      not leaves.
    - Show how the "make source/sink" rule propagates through the subtrees.
5.  The Algorithm:
    - Find a degree-2 node 'v' with neighbors 'u' and 'w'.
    - Orient the edges to form a path: u -> v -> w. This creates one "special"
      node 'v' (with both an incoming and outgoing edge) and gives 3 pairs.
    - To ensure no more "special" nodes are created, orient all remaining
      edges so that other nodes are either pure sources (only outgoing edges)
      or pure sinks (only incoming edges).
    - This is achieved by making 'u' a source for its subtree and 'w' a sink
      for its subtree.
    - The final count is 3 pairs from the special path + (N-3) pairs from the
      remaining N-3 edges, totaling exactly N pairs.
"""
from manim import *

# A configuration class for easy styling
class Cfg:
    # Colors
    BG_COLOR = BLACK
    TEXT_COLOR = WHITE
    NODE_COLOR = BLUE_C
    EDGE_COLOR = GRAY
    HIGHLIGHT_COLOR = YELLOW
    SUCCESS_COLOR = GREEN
    FAIL_COLOR = RED
    
    # Sizes & Fonts
    TITLE_FS = 48
    SUBTITLE_FS = 36
    TEXT_FS = 30
    NODE_RADIUS = 0.4
    ARROW_STROKE = 6
    ARROW_TIP = 0.25

# Set portrait orientation for shorts/reels
config.pixel_width = 1080
config.pixel_height = 1920
config.frame_width = 9
config.frame_height = 16

class ReachabilityTreeImproved(Scene):
    def construct(self):
        self.camera.background_color = Cfg.BG_COLOR
        
        self.show_intro()
        self.explain_path_graph()
        self.explain_general_tree()
        self.show_complex_example()
        self.show_conclusion()
        self.show_credits()

    def show_intro(self):
        """Displays the title and problem description."""
        title = Text("D. Reachability and Tree", font_size=Cfg.TITLE_FS).to_edge(UP)
        subtitle = Text("Exactly N Good Pairs", font_size=Cfg.SUBTITLE_FS, color=Cfg.HIGHLIGHT_COLOR)
        subtitle.next_to(title, DOWN, buff=0.4)
        
        self.play(Write(title))
        self.play(FadeIn(subtitle, shift=UP))
        self.wait(2)

        problem_text = VGroup(
            Text("Given a tree with N vertices,", font_size=Cfg.TEXT_FS),
            Text("direct its edges to create", font_size=Cfg.TEXT_FS),
            Text("exactly N 'good pairs' (a, b),", font_size=Cfg.TEXT_FS),
            Text("where b is reachable from a.", font_size=Cfg.TEXT_FS)
        ).arrange(DOWN, buff=0.3).move_to(ORIGIN)

        self.play(FadeOut(title, subtitle), Write(problem_text))
        self.wait(4)
        self.play(FadeOut(problem_text))
        self.wait(1)

    def explain_path_graph(self):
        """Explains the core logic using a simple path graph."""
        path_title = Text("Let's start with a simple case: a Path", font_size=Cfg.SUBTITLE_FS).to_edge(UP)
        self.play(Write(path_title))

        nodes_data = ["A", "B", "C", "D", "E"]
        n = len(nodes_data)
        vertices, labels, graph = self.create_graph_from_list(nodes_data)
        graph.move_to(ORIGIN).shift(UP*2)
        
        self.play(Create(graph.submobjects[1]), Write(graph.submobjects[2])) # vertices, labels
        self.play(Create(graph.submobjects[0])) # edges
        self.wait(1)

        alt_text = Text("Strategy 1: Alternate edge directions", font_size=Cfg.TEXT_FS).next_to(graph, DOWN, buff=1)
        self.play(Write(alt_text))

        arrows, pairs = self.create_alternating_arrows(nodes_data, vertices)
        self.play(LaggedStart(*[ReplacementTransform(graph.submobjects[0][i], arrows[i]) for i in range(n-1)], lag_ratio=0.5))
        
        pair_texts = VGroup(*[Text(p, font_size=Cfg.TEXT_FS, color=Cfg.SUCCESS_COLOR).next_to(a, DOWN, buff=0.3) for p, a in zip(pairs, arrows)])
        self.play(LaggedStartMap(Write, pair_texts, lag_ratio=0.5))

        result_text = Text(f"Total pairs: {n-1} = N-1", font_size=Cfg.TEXT_FS, color=Cfg.FAIL_COLOR).next_to(alt_text, DOWN, buff=1.2)
        self.play(Write(result_text))
        self.wait(2)
        self.play(FadeOut(alt_text, pair_texts, result_text))
        
        idea_text = Text("Idea: Create one directed path of length 2", t2c={'length 2': Cfg.SUCCESS_COLOR}, font_size=Cfg.TEXT_FS).next_to(graph, DOWN, buff=1)
        self.play(Write(idea_text))
        self.wait(2)

        # Modify arrows to create A <- B <- C -> D <- E
        new_arrows = VGroup(
            self.create_arrow(vertices[1], vertices[0], Cfg.SUCCESS_COLOR), # B -> A
            self.create_arrow(vertices[2], vertices[1], Cfg.SUCCESS_COLOR), # C -> B
            self.create_arrow(vertices[2], vertices[3], Cfg.HIGHLIGHT_COLOR), # C -> D
            self.create_arrow(vertices[4], vertices[3], Cfg.HIGHLIGHT_COLOR), # E -> D
        )
        self.play(Transform(arrows, new_arrows))
        self.wait(1)

        highlight_box = SurroundingRectangle(VGroup(vertices[0], vertices[1], vertices[2]), buff=0.3, color=Cfg.SUCCESS_COLOR)
        self.play(Create(highlight_box))
        # Fade out the idea_text before writing the pairs
        self.play(FadeOut(idea_text))

        pairs_text_group = VGroup(
            Text("(B, A)", font_size=Cfg.TEXT_FS), Text("(C, B)", font_size=Cfg.TEXT_FS),
            Text("(C, A)", font_size=Cfg.TEXT_FS, color=Cfg.SUCCESS_COLOR, weight=BOLD)
        ).arrange(DOWN, buff=0.2).next_to(highlight_box, DOWN, buff=0.3)
        
        path_trace = ArcBetweenPoints(vertices[2].get_center(), vertices[0].get_center(), angle=-PI/2, stroke_color=Cfg.SUCCESS_COLOR, stroke_width=4)
        self.play(Write(pairs_text_group[0:2]))
        self.play(ShowPassingFlash(path_trace, time_width=0.5), Write(pairs_text_group[2]))
        self.wait(2)

        other_pairs_group = VGroup(
            Text("(C, D)", font_size=Cfg.TEXT_FS).next_to(arrows[2], DOWN, buff=0.3),
            Text("(E, D)", font_size=Cfg.TEXT_FS).next_to(arrows[3], DOWN, buff=0.3)
        )
        self.play(Write(other_pairs_group))
        
        final_count = Text(f"Total pairs: {n} = N", font_size=Cfg.TEXT_FS, color=Cfg.SUCCESS_COLOR).next_to(idea_text, DOWN, buff=2.5)
        self.play(Write(final_count))
        self.wait(3)

        self.play(FadeOut(path_title, graph, arrows, highlight_box, pairs_text_group, other_pairs_group, final_count))

    def explain_general_tree(self):
        """Generalizes the logic to a tree, showing success and failure cases."""
        tree_title = Text("What about a general tree?", font_size=Cfg.SUBTITLE_FS).to_edge(UP)
        self.play(Write(tree_title))
        
        # Case 1: Center node has degree > 2 (FAIL)
        fail_text = Text("If the middle node's degree > 2, it fails.", font_size=Cfg.TEXT_FS, color=Cfg.FAIL_COLOR).next_to(tree_title, DOWN)
        self.play(Write(fail_text))

        node_pos = {'A': LEFT*3, 'B': ORIGIN, 'C': UP*2, 'D': RIGHT*3}
        verts, _, graph = self.create_graph_from_dict(node_pos, [('A','B'), ('C','B'), ('B','D')])
        graph.move_to(ORIGIN).shift(UP)
        self.play(FadeIn(graph))
        self.play(verts['B'].animate.set_color(Cfg.FAIL_COLOR), run_time=0.5)
        
        degree_text = Text("Degree of B is 3", font_size=Cfg.TEXT_FS)
        try_text = Text("Try A->B->D...", font_size=Cfg.TEXT_FS)
        info_text = VGroup(degree_text, try_text).arrange(DOWN).next_to(verts['B'], DOWN, buff=0.5)
        self.play(Write(info_text))

        arrow_ab = self.create_arrow(verts['A'], verts['B'], Cfg.SUCCESS_COLOR)
        arrow_bd = self.create_arrow(verts['B'], verts['D'], Cfg.SUCCESS_COLOR)
        arrow_cb = self.create_arrow(verts['C'], verts['B'], Cfg.FAIL_COLOR)
        arrows = VGroup(arrow_ab, arrow_bd, arrow_cb)
        self.play(Create(arrows[0]), Create(arrows[1]))
        self.play(Create(arrows[2]))
        
        path_cd = ArcBetweenPoints(verts['C'].get_center(), verts['D'].get_center(), angle=-PI/2, stroke_color=Cfg.FAIL_COLOR)
        extra_pair_text = Text("Creates extra pair (C,D)!", font_size=Cfg.TEXT_FS, color=Cfg.FAIL_COLOR).next_to(path_cd, UP)
        self.play(ShowPassingFlash(path_cd, time_width=0.5), Write(extra_pair_text))
        self.wait(2)
        
        self.play(FadeOut(graph, info_text, fail_text, arrows, extra_pair_text))

        # Case 2: Center node has degree = 2 (SUCCESS)
        success_text = Text("The key: Pick a node with degree 2!", font_size=Cfg.SUBTITLE_FS, color=Cfg.SUCCESS_COLOR).to_edge(UP)
        self.play(ReplacementTransform(tree_title, success_text))

        node_pos = {'A': LEFT*3+UP*2, 'B': LEFT*1.5, 'C': RIGHT*1.5, 'D': RIGHT*3+UP*2, 'E': RIGHT*1.5+DOWN*2}
        verts, _, graph = self.create_graph_from_dict(node_pos, [('A','B'), ('B','C'), ('C','D'), ('C','E')])
        graph.move_to(ORIGIN).shift(3*UP)
        self.play(FadeIn(graph))

        highlight_b = SurroundingRectangle(verts['B'], color=Cfg.HIGHLIGHT_COLOR)
        degree_b_text = Text("B has degree 2", font_size=Cfg.TEXT_FS).next_to(verts['B'], UP)
        self.play(Create(highlight_b), Write(degree_b_text))
        
        # Group explanation text on the left to avoid overlap
        explanation_text = VGroup(
            Text("1. Orient A->B->C", font_size=Cfg.TEXT_FS),
            Text("Gives 3 pairs, makes B 'special'", font_size=Cfg.TEXT_FS),
            Text("2. Make other nodes sources or sinks", font_size=Cfg.TEXT_FS),
            Text("Make C a sink for its subtree", font_size=Cfg.TEXT_FS),
            Text("Adds N-3 more pairs", font_size=Cfg.TEXT_FS)
        ).arrange(DOWN, buff=0.5, aligned_edge=LEFT).to_edge(LEFT).shift(3*DOWN)

        self.play(Write(explanation_text[0]))
        arrow_ab = self.create_arrow(verts['A'], verts['B'], Cfg.SUCCESS_COLOR)
        arrow_bc = self.create_arrow(verts['B'], verts['C'], Cfg.SUCCESS_COLOR)
        self.play(Create(arrow_ab), Create(arrow_bc))
        self.play(Write(explanation_text[1]))
        self.wait(2)

        self.play(Write(explanation_text[2]))
        self.play(Write(explanation_text[3]))
        
        arrow_dc = self.create_arrow(verts['D'], verts['C'], Cfg.HIGHLIGHT_COLOR)
        arrow_ec = self.create_arrow(verts['E'], verts['C'], Cfg.HIGHLIGHT_COLOR)
        self.play(Create(arrow_dc), Create(arrow_ec))
        
        self.play(Write(explanation_text[4]))
        self.wait(2)

        final_count = Text("Total = 3 + (N-3) = N pairs!", font_size=Cfg.SUBTITLE_FS, color=Cfg.SUCCESS_COLOR).to_edge(DOWN)
        self.play(Write(final_count))
        self.wait(3)

        self.play(FadeOut(success_text, graph, highlight_b, degree_b_text, explanation_text, VGroup(arrow_ab, arrow_bc, arrow_dc, arrow_ec), final_count))

    def show_complex_example(self):
        """Shows the algorithm on a tree where the degree-2 node's neighbors are not leaves."""
        title = Text("A More Complex Example", font_size=Cfg.SUBTITLE_FS).to_edge(UP)
        self.play(Write(title))

        # Graph where the degree-2 node (D) has non-leaf neighbors (C, E)
        node_pos = {
            'A': LEFT * 3.5 + UP * 1.5,
            'B': LEFT * 3.5 + DOWN * 1.5,
            'C': LEFT * 1.75,
            'D': ORIGIN,
            'E': RIGHT * 1.75,
            'F': RIGHT * 3.5 + UP * 1.5,
            'G': RIGHT * 3.5 + DOWN * 1.5,
        }
        edges_list = [('A','C'), ('B','C'), ('C','D'), ('D','E'), ('E','F'), ('E','G')]
        verts, _, graph = self.create_graph_from_dict(node_pos, edges_list)
        graph.move_to(ORIGIN).shift(DOWN*2)
        
        explanation = Text(
            "Here, D has degree 2, and its neighbors\nC and E both have degree > 1.",
            font_size=Cfg.TEXT_FS, line_spacing=1.2
        ).next_to(title, DOWN)
        
        self.play(FadeIn(graph))
        self.play(Write(explanation))
        self.wait(3)
        self.play(FadeOut(explanation))

        # Step 1: Find degree 2 node
        step1_text = Text("1. Find a degree-2 node: D", font_size=Cfg.TEXT_FS).next_to(title, DOWN)
        highlight_d = SurroundingRectangle(verts['D'], color=Cfg.HIGHLIGHT_COLOR)
        self.play(Write(step1_text), Create(highlight_d))
        self.wait(2)

        # Step 2: Orient special path
        step2_text = Text("2. Orient C → D → E", font_size=Cfg.TEXT_FS).next_to(step1_text, DOWN, aligned_edge=LEFT)
        self.play(Write(step2_text))
        arrow_cd = self.create_arrow(verts['C'], verts['D'], Cfg.SUCCESS_COLOR)
        arrow_de = self.create_arrow(verts['D'], verts['E'], Cfg.SUCCESS_COLOR)
        self.play(Create(arrow_cd), Create(arrow_de))
        self.wait(2)

        # Step 3: Orient subtrees based on the special path's ends
        step3_text = Text("3. Orient subtrees", font_size=Cfg.TEXT_FS).next_to(step2_text, DOWN, aligned_edge=LEFT)
        self.play(Write(step3_text))
        
        # Make C (start of path) a source for its subtree
        source_text = Text("Make C a source: C→A, C→B", font_size=Cfg.TEXT_FS, color=Cfg.HIGHLIGHT_COLOR).next_to(step3_text, DOWN, aligned_edge=LEFT)
        self.play(Write(source_text))
        arrow_ca = self.create_arrow(verts['C'], verts['A'], Cfg.HIGHLIGHT_COLOR)
        arrow_cb = self.create_arrow(verts['C'], verts['B'], Cfg.HIGHLIGHT_COLOR)
        self.play(Create(arrow_ca), Create(arrow_cb))
        self.wait(2)

        # Make E (end of path) a sink for its subtree
        sink_text = Text("Make E a sink: F→E, G→E", font_size=Cfg.TEXT_FS, color=Cfg.HIGHLIGHT_COLOR).next_to(source_text, DOWN, aligned_edge=LEFT)
        self.play(Write(sink_text))
        arrow_fe = self.create_arrow(verts['F'], verts['E'], Cfg.HIGHLIGHT_COLOR)
        arrow_ge = self.create_arrow(verts['G'], verts['E'], Cfg.HIGHLIGHT_COLOR)
        self.play(Create(arrow_fe), Create(arrow_ge))
        self.wait(2)

        # Final count
        final_count = Text("Total pairs = 7 = N", font_size=Cfg.SUBTITLE_FS, color=Cfg.SUCCESS_COLOR).to_edge(DOWN)
        self.play(Write(final_count))
        self.wait(4)

        all_mobjects = self.mobjects
        self.play(FadeOut(*all_mobjects))

    def show_conclusion(self):
        """Summarizes the final algorithm."""
        summary_title = Text("The Algorithm", font_size=Cfg.SUBTITLE_FS).to_edge(UP)
        self.play(Write(summary_title))

        summary = VGroup(
            Text("1. Find any node 'v' with degree 2."),
            Text("   (Let its neighbors be 'u' and 'w'.)"),
            Text("2. Orient edges to form u → v → w."),
            Text("3. Make 'u' a source for its subtree."),
            Text("4. Make 'w' a sink for its subtree."),
            Text("5. And keep alternating the edge direction"),            
            Text("as you go down the subtree"),
            Text("just like in the linked list."),
        ).arrange(DOWN, buff=0.5, aligned_edge=LEFT)
        
        # Ensure the text block fits within the frame width
        summary.scale_to_fit_width(config.frame_width - 1.5).move_to(ORIGIN)
        # Set font size after scaling to maintain consistency
        for line in summary:
            line.set_font_size(Cfg.TEXT_FS)

        self.play(Write(summary))
        self.wait(5)
        
        thanks = Text("Thank you for watching!", font_size=Cfg.SUBTITLE_FS, color=Cfg.HIGHLIGHT_COLOR)
        self.play(FadeOut(summary_title, summary), FadeIn(thanks))
        self.wait(2)
        self.play(FadeOut(thanks))

    def show_credits(self):
        """Displays the credits page."""
        credits_title = Text("Credits", font_size=Cfg.SUBTITLE_FS).to_edge(UP)
        self.play(Write(credits_title))
        self.wait(1)

        credits_text = VGroup(
            Text("Approach for implementation: Yash Chaphekar", font_size=Cfg.TEXT_FS,
                 t2c={"Yash Chaphekar": Cfg.HIGHLIGHT_COLOR}),
            Text("Video: Prakhar Bhandari", font_size=Cfg.TEXT_FS,
                 t2c={"Prakhar Bhandari": Cfg.HIGHLIGHT_COLOR}),
        ).arrange(DOWN, buff=0.5, aligned_edge=LEFT)

        credits_text.move_to(ORIGIN)

        self.play(Write(credits_text))
        self.wait(1)
        self.play(FadeOut(credits_title, credits_text))

    # Helper methods for creating mobjects
    def create_arrow(self, start_node, end_node, color):
        return Arrow(start_node.get_center(), end_node.get_center(), buff=Cfg.NODE_RADIUS, 
                     color=color, stroke_width=Cfg.ARROW_STROKE, max_tip_length_to_length_ratio=Cfg.ARROW_TIP)

    def create_graph_from_list(self, nodes):
        n = len(nodes)
        vertices = VGroup(*[Circle(radius=Cfg.NODE_RADIUS, color=Cfg.NODE_COLOR, fill_opacity=1, fill_color=Cfg.BG_COLOR) for _ in range(n)]).arrange(RIGHT, buff=1.0)
        labels = VGroup(*[Text(label, font_size=Cfg.TEXT_FS).move_to(v.get_center()) for label, v in zip(nodes, vertices)])
        edges = VGroup(*[Line(vertices[i].get_center(), vertices[i+1].get_center(), color=Cfg.EDGE_COLOR) for i in range(n - 1)])
        return vertices, labels, VGroup(edges, vertices, labels)

    def create_graph_from_dict(self, node_positions, edges_list):
        vertices = {name: Circle(radius=Cfg.NODE_RADIUS, color=Cfg.NODE_COLOR, fill_opacity=1, fill_color=Cfg.BG_COLOR).move_to(pos) for name, pos in node_positions.items()}
        labels = {name: Text(name, font_size=Cfg.TEXT_FS).move_to(pos) for name, pos in node_positions.items()}
        edges = VGroup(*[Line(vertices[u].get_center(), vertices[v].get_center(), color=Cfg.EDGE_COLOR) for u, v in edges_list])
        return vertices, labels, VGroup(edges, VGroup(*vertices.values()), VGroup(*labels.values()))

    def create_alternating_arrows(self, nodes, vertices):
        arrows, pairs = VGroup(), []
        for i in range(len(nodes) - 1):
            u, v = vertices[i], vertices[i+1]
            if i % 2 == 0:
                arrows.add(self.create_arrow(v, u, Cfg.HIGHLIGHT_COLOR))
                pairs.append(f"({nodes[i+1]}, {nodes[i]})")
            else:
                arrows.add(self.create_arrow(u, v, Cfg.HIGHLIGHT_COLOR))
                pairs.append(f"({nodes[i]}, {nodes[i+1]})")
        return arrows, pairs